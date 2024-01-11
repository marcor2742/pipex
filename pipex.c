/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:15 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/11 16:20:36 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void check_file(int argc, char **argv)
{
	(void)argc;
	if (access(argv[1], F_OK | R_OK) == -1)
	{
		perror("access file1");
		exit(1);
	}

}

void matrix_cmd(int argc, char **argv, t_data *data)
{
	int i;

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
	
	i = 0;
	data->pid = malloc(sizeof(pid_t) * (argc - 2));
	if (!data->pid)
	{
		perror("malloc pid");
		exit(1);
	}
}

void	free_end(int argc, t_data *data)
{
	int i;
	int j;

	i = 0;
	while (i < argc - 3)
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
	while (i < argc - 3)
	{
		free(data->path[i]);
		i++;
	}
	free(data->path);
}

void print_matrix(int argc, t_data *data)
{
	int i;
	int j;

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

void	path_execve(int argc, t_data *data)
{
	int i;

	i = 0;
	data->path = malloc(sizeof(char *) * (argc - 2));
	if (!data->path)
	{
		perror("malloc path");
		exit(1);
	}
	while (i < argc - 3)
	{
		data->path[i] = ft_strjoin("/bin/", data->cmd[i][0]);
		i++;
	}
	data->path[i] = NULL;
}

void	perror_child(int i)
{
	if (i == 1)
		perror("pipe");
	else if (i == 2)
		perror("fork");
	else if (i == 3)
		perror("dup2 stdout child");
	else if (i == 4)
		perror("execve child");
	else if (i == 5)
		perror("dup2 stdin child");
	exit (1);
}

void	ft_child(t_data *data, int i)
{
	pid_t	pid;
	int fd[2];
	
	if (pipe(fd) == -1)
		perror_child(1);
	pid = fork();
	if (pid == -1)
		perror_child(2);
	if (pid == 0)
	{
		close(fd[0]);
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			perror_child(3);
		if (execve(data->path[i], data->cmd[i], NULL) < 0)
			perror_child(4);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			perror_child(5);
		waitpid(pid , NULL, 0);
	}
}

void	ft_parent(t_data *data, int i)
{
		if (dup2(data->fileout, STDOUT_FILENO) == -1)
		{
			perror("dup2 dad");
			exit (1);
		}
		if (execve(data->path[i], data->cmd[i], NULL) < 0)
		{
			perror("execve dad");
			exit (1);
		}

	close(data->filein);
	close(data->fileout);
	close(data->fd[0]);
	close(data->fd[1]);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	check_file(argc, argv);
	data.filein = open(argv[1], O_RDONLY);
	data.fileout = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777); // append per altro coso
	if (data.filein < 0 || data.fileout < 0)
	{
		perror("open");
		free_end(argc, &data);
		return (1);
	}
	matrix_cmd(argc, argv, &data);
	path_execve(argc, &data);
	if (dup2(data.filein, STDIN_FILENO) == -1)
	{
		perror("dup2 stdin");
		exit (1);
	}
	i = 0;
	while (i < argc - 4)
	{
		ft_child(&data, i++);
	}
	ft_parent(&data, i);
	
	free_end(argc, &data);
}
