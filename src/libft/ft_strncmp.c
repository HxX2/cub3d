/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:31:44 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 03:29:19 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	i = 0;
	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (p1[i] && p2[i] && p1[i] == p2[i] && i < n - 1)
		i++;
	return (p1[i] - p2[i]);
}

// int	main(void)
// {
// 	char	s1[] = "NO ./path_to_the_north_texture.xpm";
// 	char	s2[] = "NO";
// 	printf("%d", ft_strncmp (s1, s2, 5));
// }