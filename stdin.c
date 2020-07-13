/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:25:29 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/13 18:12:05 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

int main ()
{
	int fd = 0;
	static int      j = 0;
    static  int     i = 0;
    int             ret;
    char            buf[BUFF_SIZE + 1];
    static  char    *str = "";
    char    *store;
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
	printf("%s", store);
    j = ft_strlen(store) + j;
    if (str[i])
        return (1);
    if (!str[i])
        return (0);
    else return (-1);
/*	char buf[40];
	int fd;

	fd = open("text.txt", O_RDONLY);
	fd = 0;
	read(fd, buf, 41); 
	printf ("%s", buf); */
	return (0);
}
