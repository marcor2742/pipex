/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:44:05 by marvin            #+#    #+#             */
/*   Updated: 2024/01/16 13:44:05 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	free_all_possible_path(data);
	exit (1);
}

void	perror_dup_files(int i)
{
	if (i == 1)
		perror("argc too few arguments");
	else if (i == 2)
		perror("open file");
	else if (i == 3)
		perror("dup2 file stdin");
	exit (1);
}

void	free_heredoc(t_data *data)
{
	free(data->line);
	free(data->returnline);
	exit (0);
}
