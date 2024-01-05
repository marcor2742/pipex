/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 16:47:54 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/05 17:02:31 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*ft_read(char *newline, int fd);
size_t	ft_strlen_line(char *str);
char	*ft_strchr_line(char *newline, int c);
char	*ft_strjoin_line(char *newline, char *buf);
char	*ft_correctline(char *newline);
char	*ft_resto(char *newline);

#endif