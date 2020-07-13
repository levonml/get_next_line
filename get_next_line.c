/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/13 18:07:13 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	static int 		j = 0;
	static	int		i = 0;
    int				ret;
	char			buf[BUFF_SIZE + 1];
	static  char	*str = "";
   	char	*store;
	if (fd < 0)
		return (-1);
	while((ret = read(fd, buf, BUFF_SIZE))) 
	{
				buf[ret] = '\0';		
		str = ft_strjoin(str, buf);
	}
	while (str[i] != '\n')
		i++;
	i++;
	store = ft_strsub(str, j, i-j-1);
	*line = store;
	j = ft_strlen(store) + j;
	if (str[i])
		return (1);
	if (!str[i])
		return (0);
	else return (-1);

	return (0);
}
