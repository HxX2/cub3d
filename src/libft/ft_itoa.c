/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 18:07:01 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 00:46:31 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_num(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*ft_convert(char *p, long int nu, int ln)
{
	int	s;

	s = 0;
	if (nu < 0)
	{
		nu *= -1;
		s = 1;
	}
	while (ln > 0)
	{
		p[ln - 1] = (nu % 10) + '0';
		ln--;
		nu /= 10;
	}
	if (s)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	char		*p;
	int			ln;
	long int	a;

	ln = len_num(n);
	a = n;
	p = (char *)malloc(sizeof(char) * (ln + 1));
	if (!p)
		return (NULL);
	p[ln] = '\0';
	p = ft_convert(p, a, ln);
	return (p);
}
