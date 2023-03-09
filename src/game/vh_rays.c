/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vh_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:27:20 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 15:06:48 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

t_vec	h_wall_hit(t_game *game, t_ray *ray, int *is_h_hit)
{
	t_vec	wall_hit;
	t_vec	next_stp;

	wall_hit.x = 0;
	wall_hit.y = 0;
	next_stp.x = ray->intrcp.x;
	next_stp.y = ray->intrcp.y;
	if (ray->is_up)
		next_stp.y--;
	while ((next_stp.x >= 0 && next_stp.x <= (game->scene->w_map * T_SIZE))
		&& (next_stp.y >= 0 && next_stp.y <= (game->scene->h_map * T_SIZE)))
	{
		if (ray_collision(game, next_stp.x, next_stp.y))
		{
			*is_h_hit = 1;
			wall_hit.x = next_stp.x;
			wall_hit.y = next_stp.y;
			return (wall_hit);
		}
		next_stp.x += ray->step.x;
		next_stp.y += ray->step.y;
	}
	return (wall_hit);
}

t_vec	h_ray(t_game *game, t_ray *ray, int *is_h_hit)
{
	ray->intrcp.y = floor(game->player.y / T_SIZE) * T_SIZE;
	if (ray->is_down)
		ray->intrcp.y += T_SIZE;
	ray->intrcp.x = game->player.x + (ray->intrcp.y - game->player.y)
		/ tan(ray->angle);
	ray->step.y = T_SIZE;
	if (ray->is_up)
		ray->step.y *= -1;
	else
		ray->step.y *= 1;
	ray->step.x = T_SIZE / tan(ray->angle);
	if (ray->is_left && ray->step.x > 0)
		ray->step.x *= -1;
	else
		ray->step.x *= 1;
	if (ray->is_right && ray->step.x < 0)
		ray->step.x *= -1;
	else
		ray->step.x *= 1;
	return (h_wall_hit(game, ray, is_h_hit));
}

t_vec	v_wall_hit(t_game *game, t_ray *ray, int *is_v_hit)
{
	t_vec	wall_hit;
	t_vec	next_stp;

	wall_hit.x = 0;
	wall_hit.y = 0;
	next_stp.x = ray->intrcp.x;
	next_stp.y = ray->intrcp.y;
	if (ray->is_left)
		next_stp.x--;
	while (next_stp.x >= 0 && next_stp.x <= (game->scene->w_map * T_SIZE)
		&& next_stp.y >= 0 && next_stp.y <= (game->scene->h_map * T_SIZE))
	{
		if (ray_collision(game, next_stp.x, next_stp.y))
		{
			*is_v_hit = 1;
			wall_hit.x = next_stp.x;
			wall_hit.y = next_stp.y;
			return (wall_hit);
		}
		next_stp.x += ray->step.x;
		next_stp.y += ray->step.y;
	}
	return (wall_hit);
}

t_vec	v_ray(t_game *game, t_ray *ray, int *is_v_hit)
{
	ray->intrcp.x = floor(game->player.x / T_SIZE) * T_SIZE;
	if (ray->is_right)
		ray->intrcp.x += T_SIZE;
	ray->intrcp.y = game->player.y + (ray->intrcp.x - game->player.x)
		* tan(ray->angle);
	ray->step.x = T_SIZE;
	if (ray->is_left)
		ray->step.x *= -1;
	else
		ray->step.x *= 1;
	ray->step.y = T_SIZE * tan(ray->angle);
	if (ray->is_up && ray->step.y > 0)
		ray->step.y *= -1;
	else
		ray->step.y *= 1;
	if (ray->is_down && ray->step.y < 0)
		ray->step.y *= -1;
	else
		ray->step.y *= 1;
	return (v_wall_hit(game, ray, is_v_hit));
}
