/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:47:14 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/20 01:18:11 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->scene->w_map * T_SIZE,
			game->scene->h_map * T_SIZE, "CUB3D");
	game->frame.img = mlx_new_image(game->mlx, game->scene->w_map * T_SIZE,
			game->scene->h_map * T_SIZE);
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_per_pixel,
			&game->frame.line_length,
			&game->frame.endian);
}

double get_dir(char p)
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
		return(0);
}
void	init_player(t_game *game)
{
	game->player.x = game->scene->player_x * T_SIZE;
	game->player.y = game->scene->player_y * T_SIZE;
	game->player.walk_dir = 0;
	game->player.turn_dir = 0;
	game->player.rot_ang = get_dir(game->scene->player_position);
	game->player.move_speed = 4.0;
	game->player.rot_speed = 4 * (M_PI / 180);
}