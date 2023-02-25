/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 16:04:22 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/25 03:50:14 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] && (char)c != s[i])
		i++;
	if ((char)c == s[i])
		return ((char *)(s + i));
	return (0);
}

// int	ft_strchr_int(const char *s, int c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] && (char)c != s[i])
// 		i++;
// 	if ((char)c == s[i])
// 		return (i);
// 	return (0);
// }

// int	main()
// {
// 	char	str[] = "tripouille";
// 	printf("%d", ft_strchr_int(str, 'i'));
// }