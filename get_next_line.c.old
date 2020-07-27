/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 09:23:07 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/26 23:27:25 by lstepany         ###   ########.fr       */
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
	while (str && str[j] != '\0')
	{
		if (str[j] == '\n')
			return (j);
		j++;
	}
	return (-1);
}

int	ft_list(const int *fd, t_lst **lst, char **store)
{
	t_lst *newnode;
	t_lst *temp;	
	if(*lst == NULL)
		*lst = (t_lst *)(malloc(sizeof(t_lst)));
	temp = *lst;
	while (temp->content != NULL )
	{
		if(*fd == temp->fd)
		{
			//	return(temp->content);
			*store = (temp->content);
			return(0);
			break;
		}
		temp = temp->next;
	}
	newnode = (t_lst *)malloc(sizeof(t_lst));
	//	newnode->content = NULL;
	newnode->fd = *fd;
	//	newnode->next = NULL;
	temp = newnode;
	//	printf("nc = %s\n fd = %d", newnode->content, newnode->fd);
	*store = (newnode->content);
	return(0);
}
int		read_all(const int *fd, char **store)
{
	char			buf[BUFF_SIZE + 1];
	int				ret;
	char			*temp;

	if (*fd < 0)
		return (-1);
	
	if (!(*store))
		*store = ft_strnew(0);
	while ((ret = read(*fd, buf, BUFF_SIZE)))
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
	return (ret);
}

int		get_next_line(const int fd, char **line)
{
	static	t_lst	*lst;
	char			*temp;
   	char 			*store;
   	int				ret;
	//	if(lst == NULL)
	//	lst = (t_lst *)(malloc(sizeof(t_lst)));
	ft_list(&fd, &lst, &store);
	if ((ret = read_all(&fd, &store)) < 0)
		return (-1);
	if (ret == 0 && *store == '\0')
		return (0);
	if (ft_newline(store) != -1)
	{
		*line = ft_strsub(store, 0, ft_newline(store));
		temp = ft_strdup(ft_strchr(store, '\n') + 1);
		free(store);
		store = temp;
		return (1);
	}
	if (ft_newline(store) == -1)
	{
		*line = ft_strdup(store);
		free(store);
		store = NULL;
		return (1);
	}
	return (-1);
}
