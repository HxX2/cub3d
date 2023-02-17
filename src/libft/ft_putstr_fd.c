/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 23:53:33 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/05 20:24:02 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write (fd, s, ft_strlen(s));
}

// int	main(void)
// {
// 	int fd;
// 	char s[] = "hello world";
// 	fd = open("text.txt", O_RDWR | O_CREAT);
// 	ft_putstr_fd(s, fd);
// }