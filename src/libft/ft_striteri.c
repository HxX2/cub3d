/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 18:43:47 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 21:11:02 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	if (s)
	{
		while (*(s + i))
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// void f(unsigned int i, char *c)
// {
// 	*c += i;
// }

// int main()
// {
// 	char s[] = "00000";
// 	ft_striteri(s, f);
// 	printf("%s", s);
// }