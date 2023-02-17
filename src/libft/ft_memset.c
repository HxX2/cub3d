/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 15:39:33 by gkarib            #+#    #+#             */
/*   Updated: 2022/10/22 19:04:07 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char) c;
		i++;
	}
	return (str);
}

// int	main()
// {
// 	// void *a= malloc(4);
// 	// int *b;

// 	// a = ft_memset(a, 127, 4);
// 	// a = ft_memset(a, 255, 3);
// 	// b = (int *)a;

// 	int t[2] = {1, 2};
// 	ft_memset(t, 2, 4);
// 	printf("%d", t[0]);
// }
