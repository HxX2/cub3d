/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 19:13:07 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/04 21:10:46 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*int main()
{
	char str[] = "hello";

	ft_bzero (str + 1, 3);
	printf("%s", str);
	return (0);
}*/

// int main()
// {
//   char b[]= "hello world";
//   ft_bzero(b, 5);
//   printf("%s", b);
// }