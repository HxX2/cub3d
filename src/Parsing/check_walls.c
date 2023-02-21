/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:24:46 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 00:47:08 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	white_space_surrounded_by_walls(t_scene *cub)
{
	int	x;
	int	y;

	y = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == '0' || cub->map[y][x] == 'N' ||
				cub->map[y][x] == 'S' || cub->map[y][x] == 'E' ||
				cub->map[y][x] == 'W')
			{
				if (!white_space(cub->map[y][x + 1]) ||
						!white_space(cub->map[y][x - 1]))
					return (0);
				if (!white_space(cub->map[y + 1][x]) ||
						!white_space(cub->map[y - 1][x]))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ptrlen_wall(t_scene *cub)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (++y < ft_ptrlen(cub->map))
	{
		x = 0;
		while (cub->map[y][x] == ' ' || cub->map[y][x] == '\t')
			x++;
		if (cub->map[y][x] != '1' && white_space(cub->map[y][x]))
			return (0);
		if (cub->map[y][ft_strlen(cub->map[y]) - 1] != '1' &&
			white_space(cub->map[y][ft_strlen(cub->map[y]) - 1]))
			return (0);
	}
	return (1);
}

int	surrounded_by_walls(t_scene *cub)
{
	int	x;
	int	y;
	int	a;

	x = -1;
	y = 0;
	while (cub->map[y][++x])
	{
		if (cub->map[y][x] != '1' && white_space(cub->map[y][x]))
			return (0);
	}
	x = 0;
	a = ft_ptrlen(cub->map) - 1;
	while (cub->map[a][++x])
	{
		if ((cub->map[a][x] != '1') && white_space(cub->map[a][x]))
			return (0);
	}
	if (!ptrlen_wall(cub))
		return (0);
	if (!white_space_surrounded_by_walls(cub))
		return (0);
	return (1);
}
