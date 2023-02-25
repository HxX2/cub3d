/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:45:51 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/22 01:04:12 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	valid_extension(char *file_name, char *extension)
{
	if (ft_strlen(file_name) > 4
		&& !ft_strncmp(&file_name[ft_strlen(file_name) - 4], extension, 4))
		return (1);
	return (0);
}

int	valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

bool	valid_character(char c)
{
	if (c != '0' && c != '1' && c != 'N' && c != 'S' && c != 'E'
		&& c != 'W' && white_space(c))
		return (0);
	return (1);
}

int	check_character(t_scene *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (!valid_character(cub->map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
