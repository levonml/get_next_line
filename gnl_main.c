/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:26:24 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/22 23:39:53 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/types.h>
//#include <sys/stat.h>
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
		if (argc < 2 )
	{
  	//	printf("this is printf %s\n",	argv[1]);
		fd1 = 0;
		fd2 = 0;
	}
	else
	{
		fd1 = open(argv[1], O_RDONLY);
		if (fd1 == -1)
			printf("error N %d", errno);
		/*	fd2 = open(argv[2], O_RDONLY);
		if (fd2 == -1)
		printf("error N %d", errno);*/
	}
	i = 0;
	while (i < 3)//get_next_line(fd1, &line) > 0)
	{
			get_next_line(fd1, &line);
				   	printf("%s\n", line);
			
						free(line);
		i++;
	}
	//	printf("%d\n", i);
	/*		while (j < 2)//get_next_line(fd, &line) > 0)
	{
			get_next_line(fd2, &line);
		   	printf("%s\n", line);
			
			//	free(line);
		j++;
	}
			get_next_line(fd1, &line);
		   	printf("%s\n", line);
	*/
	//	printf("fd = %d\n", fd);
	//	printf("j = %d\n", j);

	return (0);
}
