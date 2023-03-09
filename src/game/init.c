/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:47:14 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 11:22:00 by zlafou           ###   ########.fr       */
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
