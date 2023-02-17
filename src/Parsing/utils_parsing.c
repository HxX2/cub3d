/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:38:53 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:22:21 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	white_space(char c)
{
	if ((c <= 32 && c >= 0) || c == 127)
		return (0);
	return(1);
}

bool	valid_character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E' && c != 'W' && white_space(c)) // c != ' '
		return (0);
	return(1);
}

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
		i++;
	return (i);
}
