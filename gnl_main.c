/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:26:24 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/13 18:04:37 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <sys/types.h>
//#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"
#include <stdio.h>
#include <sys/errno.h>
int main(int argc, char **argv)
{
	int fd;
	char *line;
//	int i;
	int j;
	
	j = 1;
	if (argc == 1 )
	{
		//	printf("this is printf %s\n",	argv[1]);
		fd = 0;
	}
	else
	{
		fd = open(argv[1], O_RDONLY);
//	if (fd == -1)
		//	printf("error N ", errno);
	}
	while (j == 1)
	{
		j = get_next_line(0, &line);
		printf("%s", line);
//		i++;
	}
	printf("j = %d\n", j);
	return (0);
}
