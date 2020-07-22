
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/22 23:31:38 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"

int	ft_newline(char *str)
{
	int j;

	j = 0;

	while (str[j] != '\0')
	{
		if(str[j] == '\n')
			return(j);
		j++;
	}
	return(-1);
	}
void	read_all(const int fd, char **store)
{
 	char		buf[BUFF_SIZE + 1];
	int			ret;
   	char		*temp;
	char		*text;
	
	text = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)))//&& buf[ret] != EOF)
	{
		buf[ret] = '\0';
		temp = ft_strjoin(text, buf);
		free(text);
		text = temp;
		*store = ft_strdup(temp);
		if (buf[ret - 1] == '\n')
			break;
	}
}
int	get_next_line(const int fd, char **line)
{
	static char *store;

	read_all(fd, &store);
	if(*(store) && ft_newline(store) != -1)
	{
		*line = ft_strsub(store, 0, ft_newline(store));
		store = strchr(store, '\n') + 1;
		return (1);
	}
	if(store == NULL || !(*(store)))
		return(0);
	if(ft_newline(store) == -1)
	{
		*line = store;
		free(store);
		store = NULL;
		return(1);
	}
	return (-1);
}
