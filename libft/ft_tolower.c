/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstepany <lstepany@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/12 20:11:52 by lstepany          #+#    #+#             */
/*   Updated: 2020/06/22 12:07:10 by lstepany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char d;

	d = (unsigned char)c;
	if (d <= 'Z' && d >= 'A')
		return (d = d + 32);
	else
		return (c);
}
