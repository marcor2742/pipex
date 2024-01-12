/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:14 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/12 18:45:03 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include "libft/ft_printf.h"
# include "libft/get_next_line_bonus.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <stdio.h>


typedef struct s_data
{
	int		argc;
	char	**argv;
	int		filein;
	int		fileout;
	int		fd[2];
	char	***cmd;
	char	**path;
	char	*line;
	pid_t	pod;
}				t_data;

#endif