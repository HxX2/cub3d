/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:46:01 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 01:11:40 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	char			*dest;
	const char		*source;

	if (!dst && !src)
		return (0);
	if (dst == src)
		return (dst);
	i = 0;
	dest = (char *)dst;
	source = (char *)src;
	while (i < n)
	{	
		dest[i] = source[i];
		i++;
	}
	return (dest);
}

// int	main()
// {
// 	int tab1[] = {1, 2, 3,4};
// 	int tab2[] = {4, 5, 6,8};
// 	ft_memcpy(tab1, tab2, 4 * sizeof(int));
// 	printf("%d",tab1[0]);
// 	printf("%d",tab1[1]);
// 	printf("%d",tab1[2]);
// 	printf("%d",tab1[3]);
// }