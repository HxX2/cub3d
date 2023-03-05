/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:17:23 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/04 23:06:14 by gkarib           ###   ########.fr       */
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
	int p0;

	if (dx < 0 || dx > (game->scene->w_map * T_SIZE) || dy < 0 || dy > (game->scene->h_map * T_SIZE))
		return (1);
	p0 = game->scene->map[(int)((dy) / T_SIZE)][(int)((dx)/ T_SIZE)] != '0';

	return (p0);
}

double normalize_ang(double angle)
{
	angle = fmod(angle,(M_PI * 2));
	if (angle < 0)
		angle += (M_PI * 2);
	return(angle);
}

void ray_init(t_game *game, double r_angle,int i)
{
	game->rays[i].angle = normalize_ang(r_angle);
	game->rays[i].is_up = !(game->rays[i].angle > 0 && game->rays[i].angle < M_PI);
	game->rays[i].is_down = (game->rays[i].angle > 0 && game->rays[i].angle < M_PI);
	game->rays[i].is_right = (game->rays[i].angle < M_PI * 0.5 || game->rays[i].angle > M_PI * 1.5);
	game->rays[i].is_left = !(game->rays[i].angle < M_PI * 0.5 || game->rays[i].angle > M_PI * 1.5);

}

t_vec h_ray(t_game *game, t_ray *ray, int *is_h_hit)
{
	t_vec intrcp;
	t_vec step;

	intrcp.y = floor(game->player.y / T_SIZE) * T_SIZE;
	if (ray->is_down)
		intrcp.y += T_SIZE;

	intrcp.x = game->player.x + (intrcp.y - game->player.y) / tan(ray->angle);


	step.y = T_SIZE;
	if (ray->is_up)
		step.y *= -1;
	else
		step.y *= 1;
	
	step.x = T_SIZE / tan(ray->angle);
	if (ray->is_left && step.x > 0)
		step.x *= -1;
	else
		step.x *= 1;
	if (ray->is_right && step.x < 0)
		step.x *= -1;
	else
		step.x *= 1;

	t_vec 	wall_hit;
	t_vec 	next_stp;

	wall_hit.x = 0;
	wall_hit.y = 0;
	next_stp.x = intrcp.x;
	next_stp.y = intrcp.y;

	// if (ray->is_up)
	// 	next_stp.y--;

	while ((next_stp.x >= 0 && next_stp.x <= (game->scene->w_map * T_SIZE)) && (next_stp.y >= 0 && next_stp.y <= (game->scene->h_map * T_SIZE)))
	{
		if (ray_collision(game, next_stp.x, next_stp.y - (ray->is_up)))
		{
			*is_h_hit = 1;
			wall_hit.x = next_stp.x;
			wall_hit.y = next_stp.y;
			return (wall_hit);
		}
		else
		{
			next_stp.x += step.x;
			next_stp.y += step.y;
		}
	}
	return (wall_hit);
}

t_vec v_ray(t_game *game, t_ray *ray, int *is_v_hit)
{
	t_vec intrcp;
	t_vec step;

	intrcp.x = floor(game->player.x / T_SIZE) * T_SIZE;
	if (ray->is_right)
		intrcp.x += T_SIZE;

	intrcp.y = game->player.y + (intrcp.x - game->player.x) * tan(ray->angle);


	step.x = T_SIZE;
	if (ray->is_left)
		step.x *= -1;
	else
		step.x *= 1;
	
	step.y = T_SIZE * tan(ray->angle);
	if (ray->is_up && step.y > 0)
		step.y *= -1;
	else 
		step.y *= 1;
	if (ray->is_down && step.y < 0)
		step.y *= -1;
	else 
		step.y *= 1;

	t_vec 	wall_hit;
	t_vec 	next_stp;

	wall_hit.x = 0;
	wall_hit.y = 0;
	next_stp.x = intrcp.x;
	next_stp.y = intrcp.y;

	// if (ray->is_left)
	// 	next_stp.x--;
		
	while (next_stp.x >= 0 && next_stp.x <= (game->scene->w_map * T_SIZE) && next_stp.y >= 0 && next_stp.y <= (game->scene->h_map * T_SIZE))
	{
		if (ray_collision(game, next_stp.x - (ray->is_left), next_stp.y))
		{
			*is_v_hit = 1;
			wall_hit.x = next_stp.x;
			wall_hit.y = next_stp.y;
			return (wall_hit);
		}
		next_stp.x += step.x;
		next_stp.y += step.y;
	}
	return (wall_hit);
}

void cast_ray(t_game *game, t_ray *ray, int color)
{
	t_vec 	wh_v;
	t_vec 	wh_h;
	double 	h_dist;
	double 	v_dist;
	int		is_v_hit;
	int		is_h_hit;

	is_h_hit = 0;
	is_v_hit = 0;
	wh_h = h_ray(game, ray, &is_h_hit);
	wh_v = v_ray(game, ray, &is_v_hit);

	// printf("is_h_hit = %d\n", ray->is_h_hit);
	// printf("is_v_hit = %d\n", ray->is_v_hit);

	
	if (is_h_hit)
		h_dist = get_dist(game->player.x, game->player.y, wh_h.x, wh_h.y);
	else
		h_dist = __DBL_MAX__;
	if (is_v_hit)
		v_dist = get_dist(game->player.x, game->player.y, wh_v.x, wh_v.y);
	else
		v_dist = __DBL_MAX__;

	if (h_dist < v_dist)
	{
		ray->w_hit_x = wh_h.x;
		ray->w_hit_y = wh_h.y;
		ray->dist = h_dist;
		ray->is_v_hit = false;
	}
	else
	{
		ray->w_hit_x = wh_v.x;
		ray->w_hit_y = wh_v.y;
		ray->dist = v_dist;
		ray->is_v_hit = true;
	}
	color *= 0;
}

// void cast_ray(t_game *game, t_ray *ray, int color)
// {
// 	t_vec 	wh_v;
// 	t_vec 	wh_h;
// 	double 	h_dist;
// 	double 	v_dist;
// 	int		is_v_hit;
// 	int		is_h_hit;

// 	is_h_hit = 0;
// 	is_v_hit = 0;
// 	wh_h = h_ray(game, ray, &is_h_hit);
// 	wh_v = v_ray(game, ray, &is_v_hit);

// 	printf("is_h_hit = %d\n", is_h_hit);
// 	printf("is_v_hit = %d\n", is_v_hit);

	
// 	if (is_h_hit)
// 		h_dist = get_dist(game->player.x, game->player.y, wh_h.x, wh_h.y);
// 	else
// 		h_dist = __DBL_MAX__;
// 	if (is_v_hit)
// 		v_dist = get_dist(game->player.x, game->player.y, wh_v.x, wh_v.y);
// 	else
// 		v_dist = __DBL_MAX__;

// 	if (h_dist < v_dist)
// 	{
// 		ray->w_hit_x = wh_h.x;
// 		ray->w_hit_y = wh_h.y;
// 		ray->dist = h_dist;
// 	}
// 	else
// 	{
// 		ray->w_hit_x = wh_v.x;
// 		ray->w_hit_y = wh_v.y;
// 		ray->dist = v_dist;
// 	}
// 	color *= 0;
// }

void	shoot_rays(t_game *game, double angle, int color)
{ 
	int i;

	i = 0;
	angle -= (FOV / 2);
	while(i < N_RAYS)
	{
		ray_init(game, angle, i);
		cast_ray(game, &game->rays[i], color);
		angle += (FOV / WIN_W);
		i++;
	}
}