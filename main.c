/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:26:24 by lstepany          #+#    #+#             */
/*   Updated: 2020/08/07 13:39:02 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/errno.h>
int main(int argc, char **argv)
{
	int fd1;
	int fd2;
	char *line;
	int i;
	int j;
	
	j = 0;
	if (argc == 1 )
	{
  	//	printf("this is printf %s\n",	argv[1]);
		fd1 = 0;
		//fd2 = 0;
	}
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			printf("error N %d", errno);
/*		fd2 = open(argv[2], O_RDONLY);
		if (fd2 == -1)
			printf("error N %d", errno);
			}*/
		i = 1;
//	close(fd1);
//		fd2 = open("test.mine", O_RDWR);
	}
		while (get_next_line(fd1, &line) == 1)
		{
			//		write(fd2, line, ft_strlen(line));
			//	write(fd2, "\n", 1);
			//get_next_line(fd1, &line);
			printf("%s\n", line);
			free(line);
			i++;
		} 
/*			while (j < 2)//get_next_line(fd, &line) > 0)
		{
			get_next_line(fd2, &line);
		   	printf("fd2 = %s\n", line);
			free(line);
			j++;
		}
		i = 0;
		while (i < 2)//get_next_line(fd1, &line) > 0)
        {
            get_next_line(fd1, &line);
            printf("fd1 = %s\n", line);
            free(line);
            i++;
        }*/


//			get_next_line(fd1, &line);
//			printf("%s\n", line);
//	while  (i)
		//	i++;
	return (0);
}
