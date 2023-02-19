/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:11:22 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/19 21:25:21 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

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
				return(0);
			x++;
		}
		y++;
	}
	return(1);
}

int	check_direction(t_scene *cub)
{
	int	x;
	int	y;
	int FLAG;

	y = 0;
	FLAG = 0;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
				FLAG ++;
			x++;
		}
		y++;
	}
	return (FLAG);
}

void	player_coordinates(t_scene *cub)
{
	int	x;
	int	y;

	y = 0;
	cub->player_x = -1;
	cub->player_y = -1;
	while (cub->map[y])
	{
		x = 0;
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			{
				cub->player_x = x;
				cub->player_y = y;
				break;
			}
			x++;
		}
		y++;
	}
	cub->player_position = cub->map[cub->player_y][cub->player_x];
}