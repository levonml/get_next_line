/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/21 12:01:48 by lstepany         ###   ########.fr       */
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
int	get_next_line(const int fd, char **line)
{
 	char		buf[BUFF_SIZE + 1];
	int			ret;
   	char		*temp;
	char		*text;
	static char	*store = "";
	text = ft_strnew(0);
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		temp = ft_strjoin(text, buf);
		free(text);
		text = temp;
		store = text;
	}
	if(store != NULL && ft_newline(store) != -1)
	{
		*line = ft_strsub(store, 0, ft_newline(store));
		store = strchr(store, '\n') + 1;
		return (1);
	}
	if(store == NULL)
		return(0);
	else
	{
		*line = store;
		store = NULL;
		return(1);
	}
	return (-1);
}
