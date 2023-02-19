/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:47:14 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/19 20:23:30 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->mapw * T_SIZE, game->maph
			* T_SIZE, "CUB3D");
	game->frame.img = mlx_new_image(game->mlx, game->mapw * T_SIZE, game->maph
			* T_SIZE);
	game->frame.addr = mlx_get_data_addr(game->frame.img,
			&game->frame.bits_per_pixel, &game->frame.line_length,
			&game->frame.endian);
}

void	init_player(t_game *game)
{
	game->player.x = 90;
	game->player.y = 150;
	game->player.walk_dir = 0;
	game->player.turn_dir = 0;
	game->player.rot_ang = M_PI / 2;
	game->player.move_speed = 3.0;
	game->player.rot_speed = 3 * (M_PI / 180);

}