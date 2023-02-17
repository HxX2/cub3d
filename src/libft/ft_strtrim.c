/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 01:09:25 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:49:38 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	if (!s1)
		return (NULL);
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	if (!s1[i])
		return (ft_strdup(""));
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]))
		j--;
	buff = ft_substr(s1, i, j - i + 1);
	return (buff);
}

// int main()
// {
// 	printf("%s", ft_strtrim(" Hello /*/*/world", "/=*"));
// }
