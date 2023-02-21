/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:38:53 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 15:40:17 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	white_space(char c)
{
	if ((c <= 32 && c >= 0) || c == 127)
		return (0);
	return (1);
}

bool	valid_character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && white_space(c))
		return (0);
	return (1);
}

int	ft_count(char *str, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

bool	is_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	xpm_file_opened(char *str, char *path, int *fd)
{
	int	x;

	x = 0;
	while (!white_space(path[x]))
		x++;
	*fd = valid_path(path + x);
	free(path);
	if (!*fd)
		exit(printf("File -%s- couldn't open!\n", str));
}
