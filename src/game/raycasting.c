/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:17:23 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 15:35:11 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	set_vhdist(t_ray *ray, t_rcast *caster)
{
	if (caster->h_dist < caster->v_dist)
	{
		ray->w_hit_x = caster->wh_h.x;
		ray->w_hit_y = caster->wh_h.y;
		ray->dist = caster->h_dist;
		ray->is_v_hit = false;
	}
	else
	{
		ray->w_hit_x = caster->wh_v.x;
		ray->w_hit_y = caster->wh_v.y;
		ray->dist = caster->v_dist;
		ray->is_v_hit = true;
	}
}

void	cast_ray(t_game *game, t_ray *ray)
{
	t_rcast	caster;

	caster.is_h_hit = 0;
	caster.is_v_hit = 0;
	caster.wh_h = h_ray(game, ray, &caster.is_h_hit);
	caster.wh_v = v_ray(game, ray, &caster.is_v_hit);
	if (caster.is_h_hit)
		caster.h_dist = get_dist(game->player.x, game->player.y, caster.wh_h.x,
				caster.wh_h.y);
	else
		caster.h_dist = __DBL_MAX__;
	if (caster.is_v_hit)
		caster.v_dist = get_dist(game->player.x, game->player.y, caster.wh_v.x,
				caster.wh_v.y);
	else
		caster.v_dist = __DBL_MAX__;
	set_vhdist(ray, &caster);
}

void	shoot_rays(t_game *game, double angle)
{
	int	i;

	i = 0;
	angle -= (FOV / 2);
	while (i < N_RAYS)
	{
		ray_init(game, angle, i);
		cast_ray(game, &game->rays[i]);
		angle += (FOV / WIN_W);
		i++;
	}
}
