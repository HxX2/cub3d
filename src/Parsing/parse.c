/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:43:29 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 01:49:54 by gkarib           ###   ########.fr       */
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

void	rgb_hexa(t_scene *cub, char *str, char *tmp, int i)
{
	if (ft_strcmp(str, "F"))
	{
		if (i == 0)
		{
			cub->f_color = 0;
			cub->f_color += (ft_atoi(tmp) & (0xFF)) << 16;
		}
		if (i == 1)
			cub->f_color += (ft_atoi(tmp) & (0xFF)) << 8;
		if (i == 2)
			cub->f_color += (ft_atoi(tmp) & (0xFF));
	}
	if (ft_strcmp(str, "C"))
	{
		if (i == 0)
		{
			cub->c_color = 0;
			cub->c_color += (ft_atoi(tmp) & (0xFF)) << 16;
		}
		if (i == 1)
			cub->c_color += (ft_atoi(tmp) & (0xFF)) << 8;
		if (i == 2)
			cub->c_color += (ft_atoi(tmp) & (0xFF));
	}
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
		exit(printf("Error reated with the number of lines in the map!\n"));
}

int	parse_map(char *str, t_scene *cub)
{
	int	fd;

	(void) cub;
	if (!valid_extension(str, ".cub"))
		return (printf("Extension Not Valid!\n"));
	fd = valid_path(str);
	if (!fd)
		return (printf("File couldn't open!\n"));
	import_scene(fd, cub);
	import_map(cub);
	if (!check_character(cub))
		return (printf("Not a Valid Character found!"));
	if (check_direction(cub) != 1)
		return (printf("Starting Position Duplicated or not Found!"));
	if (!surrounded_by_walls(cub))
		return (printf("Not Surrounded by Walls!"));
	player_coordinates(cub);
	check_texture_and_color(cub);
	printf("no = %x\n", cub->no);
	printf("so = %x\n", cub->so);
	printf("we = %x\n", cub->we);
	printf("ea = %x\n", cub->ea);
	return (0);
}
