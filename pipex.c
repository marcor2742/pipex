/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:15 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/16 14:18:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(t_data *data, int i)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		perror_child(1, data);
	pid = fork();
	if (pid == -1)
		perror_child(2, data);
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror_child(3, data);
		if (execve(data->path[i], data->cmd[i], NULL) < 0)
			perror_child(4, data);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror_child(5, data);
		waitpid(pid, NULL, 0);
	}
}

void	ft_parent(t_data *data, int i)
{
	if (dup2(data->fileout, STDOUT_FILENO) == -1)
		perror_child(13, data);
	if (execve(data->path[i], data->cmd[i], NULL) < 0)
		perror_child(14, data);
	if (data->filein != -1)
		close(data->filein);
	if (data->fileout != -1)
		close(data->fileout);
}

void	heredoc(t_data *data)
{
	if (pipe(data->fd) == -1)
		perror_child(6, data);
	data->pod = fork();
	if (data->pod == -1)
		perror_child(7, data);
	if (data->pod == 0)
	{
		close(data->fd[0]);
		while (1)
		{
			data->line = get_next_line(STDIN_FILENO, data);
			if (ft_strncmp(data->line, data->argv[2],
					ft_strlen(data->argv[2])) == 0)
				free_heredoc(data);
			write(data->fd[1], data->line, ft_strlen(data->line));
			free(data->line);
		}
	}
	else
	{
		close(data->fd[1]);
		if (dup2(data->fd[0], STDIN_FILENO) == -1)
			perror_child(8, data);
		waitpid(data->pod, NULL, 0);
	}
}

int	dup_and_files(t_data *data)
{
	if (ft_strcmp(data->argv[1], "here_doc") == 0)
	{
		if (data->argc < 6)
			perror_dup_files(1);
		data->fileout = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (data->fileout < 0)
			perror_dup_files(2);
		heredoc(data);
		return (1);
	}
	else
	{
		if (data->argc < 5)
			perror_dup_files(1);
		check_file(data->argc, data->argv);
		data->filein = open(data->argv[1], O_RDONLY);
		data->fileout = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data->filein < 0 || data->fileout < 0)
			perror_dup_files(2);
		if (dup2(data->filein, STDIN_FILENO) == -1)
			perror_dup_files(3);
		return (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;
	int		j;

	if (argc < 5)
		return (1);
	data.argc = argc;
	data.argv = argv;
	i = dup_and_files(&data);
	matrix_cmd(argc + i, argv + i, &data);
	data.path = malloc(sizeof(char *) * (argc - 2));
	if (!data.path)
		return (1);
	path_execve(argc - i, &data, envp);
	j = 0;
	while (j < argc - i - 4)
	{
		ft_child(&data, j);
		j++;
	}
	ft_parent(&data, j);
	free_cmd_path(&data);
}
