/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:14 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/16 14:32:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "pipex_struct.h"
# include "libft/get_next_line_bonus.h"
# include "libft/libft.h"
# include "libft/ft_printf.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>

void	heredoc(t_data *data);
void	perror_dup_files(int i);
void	free_heredoc(t_data *data);
void	free_cmd_path(t_data *data);
void	ft_child(t_data *data, int i);
void	ft_parent(t_data *data, int i);
void	perror_child(int i, t_data *data);
void	check_file(int argc, char **argv);
void	free_all_possible_path(t_data *data);
void	matrix_cmd(int argc, char **argv, t_data *data);
void	path_execve(int argc, t_data *data, char **envp);
int		dup_and_files(t_data *data);

#endif