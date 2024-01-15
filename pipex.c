/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:15 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/14 23:25:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_file(int argc, char **argv)
{
	(void)argc;
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		perror("access file1");
		exit(1);
	}
}

void	matrix_cmd(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	data->cmd = malloc(sizeof(char **) * (argc - 2));
	if (!data->cmd)
	{
		perror("malloc cmd");
		exit(1);
	}
	while (i < argc - 3)
	{
		data->cmd[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	data->cmd[i] = NULL;
}

void	free_all_possible_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->all_paths[i])
	{
		free(data->all_paths[i]);
		i++;
	}
	free(data->all_paths);
}

void	free_cmd_path(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->argc - 3)
	{
		j = 0;
		while (data->cmd[i][j])
		{
			free(data->cmd[i][j]);
			j++;
		}
		free(data->cmd[i]);
		i++;
	}
	free(data->cmd);
	i = 0;
	while (i < data->argc - 3)
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
}

void	print_matrix(int argc, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc - 3)
	{
		j = 0;
		while (data->cmd[i][j])
		{
			printf("%s\n", data->cmd[i][j]);
			j++;
		}
		i++;
	}
}

void	perror_child(int i, t_data *data)
{
	if (i == 1)
		perror("pipe");
	else if (i == 2)
		perror("fork");
	else if (i == 3 || i == 13)
		perror("dup2 stdout");
	else if (i == 4 || i == 14)
		perror("execve");
	else if (i == 5 || i == 8 || i == 12)
		perror("dup2 stdin child");
	else if (i == 6)
		perror("pipe heredoc");
	else if (i == 7)
		perror("fork heredoc");
	else if (i == 9 || i == 10)
		perror("argc too few arguments");
	else if (i == 11)
		perror("open file");
	else if (i == 15)
		perror("malloc path");
	free_cmd_path(data);
	exit (1);
}

void	path_execve(int argc, t_data *data, char **envp)
{
	int		i;
	int		j;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	data->all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	j = 0;
	while (j < argc - 3 && data->all_paths[i] != NULL)
	{
		data->possible_path = ft_strjoin(data->all_paths[i],
				ft_strjoin("/", data->cmd[j][0]));
		if (access(data->possible_path, F_OK) == 0)
		{
			data->path[j++] = data->possible_path;
			i = 0;
		}
		else
			i++;
	}
	data->path[j] = NULL;
}

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
	//int	fd[2];

	if (dup2(data->fileout, STDOUT_FILENO) == -1)
		perror_child(13, data);
	if (execve(data->path[i], data->cmd[i], NULL) < 0)
		perror_child(14, data);
	close(data->filein);
	close(data->fileout);
	//close(fd[0]);
	//close(fd[1]);
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
			data->line = get_next_line(STDIN_FILENO);
			if (ft_strncmp(data->line, data->argv[2],
					ft_strlen(data->argv[2])) == 0)
				exit (1);
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
			perror_child(9, data);
		data->fileout = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_APPEND, 0777);
		if (data->fileout < 0)
			perror_child(11, data);
		heredoc(data);
		return (1);
	}
	else
	{
		if (data->argc < 5)
			perror_child(10, data);
		check_file(data->argc, data->argv);
		data->filein = open(data->argv[1], O_RDONLY);
		data->fileout = open(data->argv[data->argc - 1],
				O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (data->filein < 0 || data->fileout < 0)
			perror_child(11, data);
		if (dup2(data->filein, STDIN_FILENO) == -1)
			perror_child(12, data);
		return (0);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_data	data;
	int		i;
	int		j;

	if (argc < 5)
		perror_child(10, &data); // forse freeo troppo
	data.argc = argc;
	data.argv = argv;
	i = dup_and_files(&data);
	matrix_cmd(argc + i, argv + i, &data);
	data.path = malloc(sizeof(char *) * (argc - 2));
	if (!data.path)
		perror_child(15, &data);
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
