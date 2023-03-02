/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_implementetion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:04:26 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/02 03:13:51 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	project_wall(t_game *game)
{
	double	perp_dist; // correct the fishbow effect
	int		x;
	int		wall_strip_height;
	int		top_pix;
	int		bottom_pix;

	x = 0;
	while (x < N_RAYS)
	{
		game->rays[x].distance_pro = (WIN_W / 2) / tan(FOV / 2);
		perp_dist = game->rays[x].dist * \
			cos(game->rays[x].angle - game->player.rot_ang);
		game->rays[x].projected_wall_height = (T_SIZE / perp_dist) * game->rays[x].distance_pro;
		wall_strip_height = (int)game->rays[x].projected_wall_height;
		top_pix = (WIN_H / 2) - (wall_strip_height / 2);
		if (top_pix < 0)
			top_pix = 0;
		bottom_pix = (WIN_H / 2) + (wall_strip_height / 2);
		if (bottom_pix > WIN_H)
			bottom_pix = WIN_H;
		put_sldrect (game, x, top_pix, x + 1, bottom_pix, 0xFFFFFF);
		x++;
	}
}
