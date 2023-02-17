/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 18:11:22 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:21:46 by gkarib           ###   ########.fr       */
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
			// > %d = %c\n", x, cub->map[y][x]);
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
// N,S,E or W
	int	x;
	int	y;
	int FLAG;

	y = 0;
	FLAG = 0;
	while (cub->map[y])
	{
		x = 0;
		// printf("===> %d = %s\n", x, cub->map[y]);
		while (cub->map[y][x])
		{
			if (cub->map[y][x] == 'N' || cub->map[y][x] == 'S' || cub->map[y][x] == 'E' || cub->map[y][x] == 'W')
			// {
			// 	printf("line = %d %s, x = %d, %c\n", y, cub->map[y], x, cub->map[y][x]);
				FLAG ++;
			// }
			x++;
		}
		y++;
	}
	// printf("FLAG = %d\n", FLAG);
	// if stat => check num of flags 
	return (FLAG);
}