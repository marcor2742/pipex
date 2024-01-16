/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:47:54 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/16 14:33:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stddef.h>
# include <stdlib.h>
# include "../pipex_struct.h"

char	*get_next_line(int fd, t_data *data);
char	*ft_read(char *newline, int fd);
size_t	ft_strlen_line(char *str);
char	*ft_strchr_line(char *newline, int c);
char	*ft_strjoin_line(char *newline, char *buf);
char	*ft_correctline(char *newline);
char	*ft_resto(char *newline, t_data *data);
int		ft_strcmp2(const char *str1, const char *str2);

#endif