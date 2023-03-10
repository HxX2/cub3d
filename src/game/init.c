/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:47:14 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/10 23:09:18 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_mmdir(char p)
{
	if (p == 'N')
		return (-(M_PI_2));
	else if (p == 'S')
		return (M_PI_2);
	else if (p == 'W')
		return (0);
	else if (p == 'E')
		return (M_PI);
	else
		return (0);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIN_W, WIN_H, "CUB3D");
	game->frame.img = mlx_new_image(game->mlx, WIN_W, WIN_H);
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_per_pixel,
			&game->frame.line_length,
			&game->frame.endian);
	game->rays = ft_xalloc(N_RAYS * sizeof(t_ray));
	game->n.img = mlx_xpm_file_to_image(game->mlx, "assets/N.xpm",
			&game->n.width, &game->n.height);
	if (!game->n.img)
		exit (printf("Error: related with the -n- xpm file"));
	game->n.addr = mlx_get_data_addr(game->n.img,
			&game->n.bits_per_pixel, &game->n.line_length,
			&game->n.endian);
	game->mm_ang = get_mmdir(game->scene->player_direction);
}

double	get_dir(char p)
{
	if (p == 'N')
		return (-(M_PI_2));
	else if (p == 'S')
		return (M_PI_2);
	else if (p == 'W')
		return (M_PI);
	else if (p == 'E')
		return (0);
	else
		return (0);
}

void	init_player(t_game *game)
{
	game->player.x = (game->scene->player_x * T_SIZE) + 32;
	game->player.y = (game->scene->player_y * T_SIZE) + 32;
	game->player.walk_dir = 0;
	game->player.turn_dir = 0;
	game->player.rot_ang = get_dir(game->scene->player_direction);
	game->player.move_speed = 10.0;
	game->player.rot_speed = 4 * (M_PI / 180);
}

void	load_textures(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->scene->no_path,
			&game->north.width, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img,
			&game->north.bits_per_pixel, &game->north.line_length,
			&game->north.endian);
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->scene->so_path,
			&game->south.width, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img,
			&game->south.bits_per_pixel, &game->south.line_length,
			&game->south.endian);
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->scene->we_path,
			&game->west.width, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img,
			&game->west.bits_per_pixel, &game->west.line_length,
			&game->west.endian);
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->scene->ea_path,
			&game->east.width, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img,
			&game->east.bits_per_pixel, &game->east.line_length,
			&game->east.endian);
}
