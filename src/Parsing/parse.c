/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:43:29 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/19 21:30:16 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_wall_delimiter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
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
		if (ft_directions(cub, "NO") || ft_directions(cub, "SO") || ft_directions(cub, "WE") || ft_directions(cub, "EA"))
		// if (texture(cub, "NO"))
			return ;
		if (ft_colors(cub, "F") || ft_colors(cub, "C"))
			return ;
	}
	else
		exit(printf("Error reated with the number of lines in the map!\n"));
}


int	parse_map(char *str, t_scene *cub)
{
	int fd;
	
	(void) cub;
	if (!valid_extension(str, ".cub"))
		return (printf("Extension Not Valid!\n"));
	fd = valid_path(str);
	if (!fd)
		return (printf("File couldn't open!\n"));


	import_scene(fd, cub);

	
	// int i = 0;
	// while (cub->scene[i])
	// {
	// 	printf("%s\n", cub->scene[i]);
	// 	i++;
	// }
	
	check_texture_and_color(cub);
	import_map(cub);
	
	// int i = 0;
	// while (cub->map[i])
	// {
	// 	printf("%s\n", cub->map[i]); // sometimes seg, and one leak !
	// 	i++;
	// }
	
	if (!check_character(cub))
		return(printf("Not a Valid Character found!"));
	if (check_direction(cub) != 1)
		return(printf("Starting Position Duplicated or not Found!"));
	
	if (!surrounded_by_walls(cub))
		return(printf("Not Surrounded by Walls!"));
	
	player_coordinates(cub);
	// printf("x = %d\n", cub->player_x);
	// printf("y = %d\n", cub->player_y);
	// printf("player = %c\n", cub->player_position);
	
	return (0);
}