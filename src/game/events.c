/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:25:36 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/04 22:37:33 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"
#include <time.h>

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
	else if (keycode == KEY_ESC)
		exit(1);
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

	p0 = game->scene->map[(int)((game->player.y + dy) / T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';
	p1 = game->scene->map[(int)((game->player.y + dy) / T_SIZE)][(int)(game->player.x / T_SIZE)] != '1';
	p2 = game->scene->map[(int)((game->player.y) / T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';

	return (p0 && p1 && p2);
}

void render_map(t_game *game)
{
	for (int i = 0; i < game->scene->h_map; i++)
	{
		for (int j = 0; j < game->scene->w_map; j++)
		{
			if (game->scene->map[i][j] == '1')
				put_sldrect(game, j * T_SIZE, i * T_SIZE, j * T_SIZE, i * T_SIZE, 0x1794C2);
			else if (game->scene->map[i][j] == ' ')
				put_sldrect(game, j * T_SIZE, i * T_SIZE, j * T_SIZE, i * T_SIZE, 0x000000);
			else
				put_sldrect(game, j * T_SIZE, i * T_SIZE, j * T_SIZE, i * T_SIZE, 0xFFFFFF);
		}
	}
}

int	render_frame(t_game *game)
{
	double dx;
	double dy;

    clock_t current_time = clock();
    static clock_t last_time = 0;
    double time_elapsed = (double)(current_time - last_time) / CLOCKS_PER_SEC;
    last_time = current_time;
    double fps = 1.0 / time_elapsed;
	(void)fps;
	update_direction(game, &dx, &dy);
	if (in_collision(game, dx, dy))
	{
		game->player.x += dx;
		game->player.y += dy;
	}
	// printf("\rFPS = %d | dir ection = %d rot_ang = %f player_x = %f player_y = %f\n", (int)floor(fps), game->player.walk_dir, game->player.rot_ang, game->player.x, game->player.y);
	// render_map(game);
	// put_sldcir(game, game->player.x, game->player.y , 8, 0xFF4040);
	// put_line(game, game->player.x, game->player.y, game->player.rot_ang, 40, 0xFF4040);
	shoot_rays(game, game->player.rot_ang, 0x86C6D5);
	put_sldrect(game, 0, 0, WIN_W, WIN_H/2, game->scene->c_color);
	put_sldrect(game,0,WIN_H/2,WIN_W,WIN_H,game->scene->f_color);
	project_wall(game);
	mlx_put_image_to_window(game->mlx, game->win, game->frame.img, 0, 0);
	return (0);
}
