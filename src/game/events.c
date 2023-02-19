/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:25:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/19 20:26:25 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_press(int keycode, void *param)
{
	t_game		*game;

	game = (t_game *)param;
	if (keycode == KEY_W)
		game->player.walk_dir = 1;
	else if (keycode == KEY_D)
		game->player.walk_dir = 2;
	else if (keycode == KEY_S)
		game->player.walk_dir = -1;
	else if (keycode == KEY_A)
		game->player.walk_dir = -2;
	else if (keycode == KEY_LEFT)
		game->player.turn_dir = -1;
	else if (keycode == KEY_RIGHT)
		game->player.turn_dir = 1;
	
	return (0);
}

int	key_release(int keycode, void *param)
{
	t_game		*game;

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
		game->player.turn_dir = 0;
	else if (keycode == KEY_RIGHT)
		game->player.turn_dir = 0;
	return (0);
}

void	update_direction(t_game *game, double *dx, double *dy)
{
	game->player.rot_ang += game->player.turn_dir * game->player.rot_speed;
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
		*dx = cos(game->player.rot_ang) * (game->player.walk_dir * game->player.move_speed);
		*dy = sin(game->player.rot_ang) * (game->player.walk_dir * game->player.move_speed);   
	}
}

int	in_collision(t_game *game, double dx, double dy)
{
	int p0;
	int p1;
	int p2;

	p0 = game->map[(int)((game->player.y + dy) / T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';
	p1 = game->map[(int)((game->player.y + dy) / T_SIZE)][(int)(game->player.x / T_SIZE)] != '1';
	p2 = game->map[(int)((game->player.y) / T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';

	return (p0 && p1 && p2);
}

void render_map(t_game *game)
{
	for (int i = 0; i < game->maph; i++)
	{
		for (int j = 0; j < game->mapw; j++)
		{
			if (game->map[i][j] == '1')
				put_sldrect(game, j * T_SIZE, i * T_SIZE, j * T_SIZE, i * T_SIZE, 0x1794C2);
			else
				put_sldrect(game, j * T_SIZE, i * T_SIZE, j * T_SIZE, i * T_SIZE, 0xFFFFFF);
		}
	}
}

int	render_frame(t_game *game)
{
	double dx;
	double dy;

	update_direction(game, &dx, &dy);
	if (in_collision(game, dx, dy))
	{
		game->player.x += dx;
		game->player.y += dy;
	}
	printf("direction = %d rot_ang = %f player_x = %f player_y = %f\n", game->player.walk_dir, game->player.rot_ang, game->player.x, game->player.y);
	render_map(game);
	put_sldcir(game, game->player.x, game->player.y , 8, 0xFF4040);
	put_line(game, game->player.x, game->player.y, game->player.x + cos(game->player.rot_ang) * 40 , game->player.y + sin(game->player.rot_ang) * 40, 0xFF4040);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);

	return (0);
}