/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 23:24:46 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:21:46 by gkarib           ###   ########.fr       */
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
		// printf("\ny = %d => %s\n", y, cub->map[y]);
		while (cub->map[y][x])
		{
			// printf("%c", cub->map[y][x]);

			if (cub->map[y][x] == '0')
			{
				if (!white_space(cub->map[y][x + 1]))
				// {
					// printf("x = %d '%d'\n", x, cub->map[y][x + 1]);
					// printf("x + 1");
					return (0);
				// }
				if (!white_space(cub->map[y][x - 1]))
				// {
					// printf("x - 1");
					return (0);
				// }
				if (!white_space(cub->map[y + 1][x]))
				// {
					// printf("y + 1");
					return (0);
				// }
				if (!white_space(cub->map[y - 1][x]))
				// {
					// printf("x = %d '%d'\n", x, cub->map[y - 1][x]);
					// printf("y - 1 = %d\n", y - 1);
					return (0);
				// }
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	surrounded_by_walls(t_scene *cub)
{
	int	x;
	int	y;
	
	x = 0;
	y = 0;
	while (cub->map[y][++x])
	{
		if (cub->map[y][x] != '1' && white_space(cub->map[y][x]))
			return (0);
		// return (printf("surrounded_by_walls: error line 'X'\n"));
		// return (printf("surrounded_by_walls: error end line 'X'\n"));
	}
	x = 0;
	int a = ft_ptrlen(cub->map) - 1;
	while (cub->map[a][++x])
	{
		if ((cub->map[a][x] != '1') && white_space(cub->map[a][x]))
			return (0);
				// return (printf("surrounded_by_walls: error end line 'X'\n"));
	}
	// printf("%d\n", y);
	// printf("%d\n", x);
	// y = 0;
	while (++y < ft_ptrlen(cub->map))
	{
		x = 0;
		while (cub->map[y][x] == ' ' || cub->map[y][x] == '\t')
			x++;
		if (cub->map[y][x] != '1' && white_space(cub->map[y][x]))
			// return (printf("surrounded_by_walls: error line 'Y'\n"));
			return (0);
		if (cub->map[y][ft_strlen(cub->map[y]) - 1] != '1' && white_space(cub->map[y][ft_strlen(cub->map[y]) - 1]))
			// return (printf("surrounded_by_walls: error end line 'Y'\n"));
			return (0);
	}
	if (!white_space_surrounded_by_walls(cub))
		return(0);
	return (1);
}