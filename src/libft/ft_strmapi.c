/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 22:06:46 by gkarib            #+#    #+#             */
/*   Updated: 2021/12/06 00:11:20 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	ret = malloc (ft_strlen(s) + 1);
	if (!ret)
		return (NULL);
	while (s[i])
	{
		ret[i] = f(i, s[i]);
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
// char	f(unsigned int i, char c)
// {
// 	(void)i;
// 	return (c + 1);
// }
// int	main()
// {
// 	char	s[] = "hello world";
// 	printf("%s", ft_strmapi(s, f));
// }