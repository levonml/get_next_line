/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 17:25:29 by lstepany          #+#    #+#             */
/*   Updated: 2020/07/17 16:39:56 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "libft.h"

t_lst *ft_read_whole(int fd)
{
	t_lst *head;
	t_lst *temp;
	t_lst *newnode;
	int		ret;
	char	buf[6];
	head = NULL;
	while((ret = read(fd, buf, 5)))
	{
		buf[ret] = '\0';		
		newnode = (t_lst *)malloc(sizeof(t_lst));
		newnode->content = ft_strdup(buf);
		newnode->next = NULL;
		if (head == NULL)
			head = newnode;
		else
		{
			temp = head;
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = newnode;
		}
	}
	return(head);
}
int main ()
{
		int fd;
	//	 int             ret;
	//  char            buf[100];
		 	t_lst *text;
	//		t_list *head;
	//	t_list *temp;
					t_lst *p;
		//	head = NULL;
	//	if (argc == 1)
	//	fd = 0;
	fd = open("text.txt", O_RDONLY);
	if(fd == -1)
		return(0);
		text = ft_read_whole(fd);
	p = text;
	while(p != NULL)
  		{
			printf("%s", p->content);
			p = p->next;
		}
		/*	p = text;
		while (p->next != NULL)
		{
			free(p);
			p = p->next;
		}
		free(p);
		*/
	// while (str[i] != 'w')
	//  i++;
	//    i++;
	//  store = ft_strsub(str, j, i-j);
	//	printf("%s", store);
	
	//  j = ft_strlen(store) + j;
	//	i++;
	//		printf("aaaaaaa\n%d", ret);
	//	if (str[i])
	//		return (1);
	//	if (!str[i])
	//		return (0);
	//	else
	//	return (-1);
		
/*	char buf[40];
	int fd;

	fd = open("text.txt", O_RDONLY);
	fd = 0;
	read(fd, buf, 41); 
	printf ("%s", buf); */
	return (0);
}
