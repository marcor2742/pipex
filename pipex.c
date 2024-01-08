/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruggier <mruggier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:07:15 by mruggier          #+#    #+#             */
/*   Updated: 2024/01/08 18:40:43 by mruggier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	int file[2];
	int fd[2];

	file[0] = open("file1", O_RDONLY);
	file[1] = open("file2", O_WRONLY);
	if (file[0] < 0 || file[1] < 0)
	{
		perror("open");
		return (1);
	}
	if (dup2(file[1], STDOUT_FILENO) < 0)
	{
		perror("dup2");
		return (1);
	}

	if (pipe(fd) < 0)
	{
		perror("pipe");
		return (1);
	}
	
	//check fork
	if (fork() == 0) {
        // primo comando: grep -o 'v' file1
        dup2(file[0], STDIN_FILENO); // collega l'input della pipe allo stdin
        dup2(fd[1], STDOUT_FILENO); // collega l'output della pipe allo stdout
        close(fd[0]);
        char *args[] = {"grep", "-o", "v", NULL};
        execve("/bin/grep", args, NULL);
    }

    if (fork() == 0) {
        // secondo comando: wc -l > file2
        dup2(fd[0], STDIN_FILENO); // collega l'input della pipe allo stdin
        dup2(file[1], STDOUT_FILENO); // collega l'output della pipe allo stdout
        close(fd[1]);
        char *args[] = {"wc", "-l", NULL};
        execve("/usr/bin/wc", args, NULL);
    }
	
	close(file[0]);
    close(file[1]);
	close(fd[0]);
	close(fd[1]);
    wait(NULL); // aspetta che il primo processo figlio termini
    wait(NULL); // aspetta che il secondo processo figlio termini

	
	//fork per fare sia execve che stampare in 2 file
	// char *args[] = {"ls", "-l", NULL};
    // execve("/bin/ls", args, NULL);

	//dup2 per scrivere quello che verrebbe in stdout in un file
}