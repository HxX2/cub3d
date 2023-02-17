/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 11:34:31 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:24:12 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	j;

	j = 0;
	if (!s)
		return (NULL);
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	ret = malloc (len + 1);
	if (!ret)
		return (NULL);
	while (start < ft_strlen(s) && j < len)
		ret[j++] = s[start++];
	ret[j] = '\0';
	return (ret);
}

// int main ()
// {
//   char s[] = "klllllllll";
//   char s2[] = "ll";
//   printf("%s", ft_substr(s, s2, 6));
// }