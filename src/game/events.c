/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:25:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 17:25:30 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <time.h>

int	key_press(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->player.walk_dir = 1;
	else if (keycode == KEY_D)
		game->player.walk_dir = -2;
	else if (keycode == KEY_S)
		game->player.walk_dir = -1;
	else if (keycode == KEY_A)
		game->player.walk_dir = 2;
	else if (keycode == KEY_LEFT)
	{
		game->mm_dir = 1;
		game->player.turn_dir = -1;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->mm_dir = -1;
		game->player.turn_dir = 1;
	}
	else if (keycode == KEY_ESC)
		exit(1);
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->player.walk_dir = 0;
	else if (keycode == KEY_D)
		game->player.walk_dir = 0;
	else if (keycode == KEY_S)
		game->player.walk_dir = 0;
	else if (keycode == KEY_A)
		game->player.walk_dir = 0;
	else if (keycode == KEY_LEFT)
	{
		game->mm_dir = 0;
		game->player.turn_dir = 0;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->mm_dir = 0;
		game->player.turn_dir = 0;
	}
	return (0);
}

void	update_direction(t_game *game, double *dx, double *dy)
{
	game->player.rot_ang += game->player.turn_dir * game->player.rot_speed;
	game->mm_ang += game->mm_dir * game->player.rot_speed;
	if (game->player.walk_dir == 2)
	{
		*dx = cos(game->player.rot_ang - M_PI_2) * game->player.move_speed;
		*dy = sin(game->player.rot_ang - M_PI_2) * game->player.move_speed;
	}
	else if (game->player.walk_dir == -2)
	{
		*dx = cos(game->player.rot_ang + M_PI_2) * game->player.move_speed;
		*dy = sin(game->player.rot_ang + M_PI_2) * game->player.move_speed;
	}
	else
	{
		*dx = cos(game->player.rot_ang) * (game->player.walk_dir
				* game->player.move_speed);
		*dy = sin(game->player.rot_ang) * (game->player.walk_dir
				* game->player.move_speed);
	}
}

int	render_frame(t_game *game)
{
	double			dx;
	double			dy;

	update_direction(game, &dx, &dy);
	if (in_collision(game, dx, dy))
	{
		game->player.x += dx;
		game->player.y += dy;
	}
	shoot_rays(game, game->player.rot_ang);
	put_cf(game);
	project_wall(game);
	put_minimap(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}
