/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:43:29 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/25 04:40:17 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_wall_delimiter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!valid_character(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	check_texture_and_color(t_scene *cub)
{
	int	y;

	y = 0;
	while (cub->scene[y])
	{
		if (find_wall_delimiter(cub->scene[y]))
			break ;
		y++;
	}
	if (y == 6)
	{
		if (ft_directions(cub, "NO") || ft_directions(cub, "SO")
			|| ft_directions(cub, "WE") || ft_directions(cub, "EA"))
			return ;
		if (ft_colors(cub, "F") || ft_colors(cub, "C"))
			return ;
	}
	else
		exit(printf("Error:"
				" reated with the number of the texture lines in the map!\n"));
}

int	parse_map(char *str, t_scene *cub)
{
	int	fd;

	if (!valid_extension(str, ".cub"))
		exit(printf("Error: Extension Not Valid!\n"));
	fd = valid_path(str);
	if (!fd)
		exit(printf("Error: File couldn't open!\n"));
	import_scene(fd, cub);
	check_texture_and_color(cub);
	import_map(cub);
	if (!check_character(cub))
		exit(printf("Error: Not a Valid Character found!\n"));
	if (check_direction(cub) != 1)
		exit(printf("Error: Starting Position Duplicated or not Found!\n"));
	if (!map_surrounded_by_walls(cub))
		exit(printf("Error: Not Surrounded by Walls!\n"));
	player_coordinates(cub);
	return (0);
}
