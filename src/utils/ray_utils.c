/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 08:54:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 11:21:43 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

double	get_dist(double x1, double y1, double x2, double y2)
{
	double	dx;
	double	dy;

	dx = (x2 - x1);
	dy = (y2 - y1);
	return (sqrt(dx * dx + dy * dy));
}

int	ray_collision(t_game *game, double dx, double dy)
{
	int	p0;

	if (dx < 0 || dx >= (game->scene->w_map * T_SIZE) || dy < 0
		|| dy >= (game->scene->h_map * T_SIZE))
		return (1);
	p0 = game->scene->map[(int)((dy) / T_SIZE)][(int)((dx) / T_SIZE)] == '1';
	return (p0);
}

double	normalize_ang(double angle)
{
	angle = fmod(angle, (M_PI * 2));
	if (angle < 0)
		angle += (M_PI * 2);
	return (angle);
}

void	ray_init(t_game *game, double r_angle, int i)
{
	game->rays[i].angle = normalize_ang(r_angle);
	game->rays[i].is_up = !(game->rays[i].angle > 0
			&& game->rays[i].angle < M_PI);
	game->rays[i].is_down = (game->rays[i].angle > 0
			&& game->rays[i].angle < M_PI);
	game->rays[i].is_right = (game->rays[i].angle < M_PI * 0.5
			|| game->rays[i].angle > M_PI * 1.5);
	game->rays[i].is_left = !(game->rays[i].angle < M_PI * 0.5
			|| game->rays[i].angle > M_PI * 1.5);
}
