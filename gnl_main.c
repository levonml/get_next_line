/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:26:24 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/12 23:20:52 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
	int fd;
	char *line;
	int i;
	static int j;
	
	i = 0;
	fd = open("text.txt", O_RDONLY);
	while (i < 4)
	{
		j = get_next_line(fd, &line);
		printf("%s", line);
		i++;
	}
	printf("j = %d\n", j);
	return (0);
}