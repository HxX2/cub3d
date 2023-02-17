/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:15:37 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 17:28:30 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	if (to_find[i] == '\0')
	{
		return (str);
	}
	else
	{
		while (str[i] != '\0')
		{
			j = 0;
			while (to_find[j] == str[i + j])
			{
				if (to_find[j + 1] == '\0')
				{
					return (&str[i]);
				}
				j++;
			}
			i++;
		}
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char	c[] = "c 03 ex 04";
// 	char	d[] = "03";

// 	printf("%s", ft_strstr(c, d));
// 	return (0);
// }
