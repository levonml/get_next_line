/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/24 15:50:49 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "libft.h"
#include <stdlib.h>
#include "get_next_line.h"

int		ft_newline(char *str)
{
	int				j;

	j = 0;
	while (str[j] != '\0')
	{
		if (str[j] == '\n')
			return (j);
		j++;
	}
	return (-1);
}

int		read_all(const int fd, char **store)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*temp;

	if (!(*store))
		*store = ft_strnew(0);
	if (fd < 0)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) && buf[ret] != EOF)
	{
		if (ret < 0)
			return (-1);
		buf[ret] = '\0';
		temp = ft_strjoin(*store, buf);
		free(*store);
		*store = ft_strdup(temp);
		free(temp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static	char	*store;
	char			*temp;

	if (read_all(fd, &store) < 0)
		return (-1);
	if ((store) && ft_newline(store) != -1)
	{
		*line = ft_strsub(store, 0, ft_newline(store));
		temp = ft_strdup(ft_strchr(store, '\n') + 1);
		free(store);
		store = temp;
		return (1);
	}
	if (!(*(store)))
		return (0);
	if (store == NULL)
		return (-1);
	if (ft_newline(store) == -1)
	{
		*line = ft_strdup(store);
		free(store);
		store = NULL;
		return (1);
	}
	return (-1);
}
