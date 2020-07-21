/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/21 15:10:20 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
   	char   			buf[BUFF_SIZE];
    char	*store;
	int				ret;
	char *str;
	char *temp;

   	store = ft_strnew(0);
		if (fd < 0)
		return (-1);
		while ((ret = read(fd, buf, 1)))// && buf[ret] == EOF)
	{
		if (buf[ret - 1] == '\n')
		{
			//	printf("ret = %d\n", ret);
			//	printf("buf = %c", buf[1]);
			
			//		buf[ret] = '\0';
			//	store = ft_strdup(store);
			break;
		}
		else
		{
			str = ft_strsub(buf, 0, 1);
			//	temp = store;
			temp = ft_strjoin(store, str);
			
			free(str);
		   	free(store);
			store = temp;
			//	stat = 
		}
	}
	*line = store;
	if (ret)
		return(1);
	if (!ret)
		return(0);
	return (-1);
}
