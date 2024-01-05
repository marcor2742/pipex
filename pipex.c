/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:15 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/05 18:43:01 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	
	i have to write in the terminal ./pipex "ls -l" and put it in execve. but that function doesn't need "ls -l" but "ls" "-l", how ca i do?
	char *args[] = {"ls", "-l", NULL};
    execve("/bin/ls", args, NULL);
}