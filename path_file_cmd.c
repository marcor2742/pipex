/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_file_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:48:01 by marvin            #+#    #+#             */
/*   Updated: 2024/01/16 13:48:01 by marvin           ###   ########.fr       */
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
		exit (1);
	}
	while (i < argc - 3)
	{
		data->cmd[i] = ft_split(argv[i + 2], ' ');
		i++;
	}
	data->cmd[i] = NULL;
}

void	path_execve(int argc, t_data *data, char **envp)
{
	int		i;
	int		j;
	char	*tmp_path;
	char	*possible_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	data->all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	j = 0;
	while (j < argc - 3 && data->all_paths[i] != NULL)
	{
		tmp_path = ft_strjoin("/", data->cmd[j][0]);
		possible_path = ft_strjoin(data->all_paths[i], tmp_path);
		free(tmp_path);
		i++;
		if (access(possible_path, F_OK) == 0)
		{
			data->path[j++] = ft_strdup(possible_path);
			i = 0;
		}
		free(possible_path);
	}
	data->path[j] = NULL;
}
