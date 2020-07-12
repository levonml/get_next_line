/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/12 23:21:26 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static int 		j = 0;
	static	int		i = 0;
    int				ret;
	char			buf[BUFF_SIZE + 1];
	static  char	*str = "";
   	char	*store;
	while((ret = read(fd, buf, BUFF_SIZE))) 
	{
				buf[ret] = '\0';
		
		str = ft_strjoin(str, buf);
	}
	while (str[i] != '\n')
		i++;
	i++;
	store = ft_strsub(str, j, i-j);
	*line = store;
	j = ft_strlen(store) + j;
	return (i);
}
