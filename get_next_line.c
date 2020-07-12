/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/12 20:17:03 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int		i;
    int 	ret;
	char 	buf[BUFF_SIZE];
	static char *str = "";
	static	char *store = "";
	//	str = "";
	//	store = "";
	while((ret = read(fd, buf, BUFF_SIZE + 1))) 
	{
		buf[ret] = '\0';
		
		str = ft_strjoin(str, buf);
	}
	i = 0;
	while (str[i] != '\n')
		i++;
	store = ft_strsub(str, ft_strlen(store), i);
	*line = store;
	store = store + i;
	return (ret);
}
