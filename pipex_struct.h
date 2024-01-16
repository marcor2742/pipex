/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:56:58 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/16 15:56:58 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_STRUCT_H
# define PIPEX_STRUCT_H

# include <sys/types.h>
# include <sys/stat.h>

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
	char	**all_paths;
	char	*possible_path;
	char	*returnline;
	pid_t	pod;
}				t_data;

#endif