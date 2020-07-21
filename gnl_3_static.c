/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 09:54:26 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/20 16:38:05 by lstepany         ###   ########.fr       */
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
    static char	*str = "";
    char	*store;
	if (fd < 0)
		return (-1);
	//	str = ft_strnew(0);
	while((ret = read(fd, buf, BUFF_SIZE))) 
	{
				buf[ret] = '\0';		
		str = ft_strjoin(str, buf);
	}
	printf("str = %s", str);
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
