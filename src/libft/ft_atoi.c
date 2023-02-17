/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:48:09 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 22:03:39 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				s;
	unsigned long	res;

	i = 0;
	s = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] && str[i] <= '9' && str[i] >= '0')
	{
		res = res * 10 + (str[i] - '0');
		if (res > 9223372036854775807 && s == 1)
			return (-1);
		else if (res > 9223372036854775807 && s == -1)
			return (0);
		i++;
	}
	return (res * s);
}

// int	main(void)
// {
// 	printf("%ld\n", ft_atoi("--4294967295"));
// 	printf("%d", atoi("--4294967295"));
// }
