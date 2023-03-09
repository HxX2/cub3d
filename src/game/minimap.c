/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 03:36:27 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 12:08:28 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_mappxl(t_game *game, int x, int y, double angle)
{
	int	dx;
	int	dy;

	dx = game->player.x + (x - (WIN_W - 200));
	dy = game->player.y + (y - (WIN_H - 200));
	rot_pxl(&x, &y, (angle + M_PI_2));
	if ((dx < 0 || dx >= (game->scene->w_map * T_SIZE) || dy < 0
			|| dy >= (game->scene->h_map * T_SIZE)))
		put_pxl(&game->frame, x, y, game->scene->c_color);
	else if (game->scene->map[(int)(dy / T_SIZE)][(int)(dx / T_SIZE)] == '1')
		put_pxl(&game->frame, x, y, 0x513821);
	else if (game->scene->map[(int)(dy / T_SIZE)][(int)(dx / T_SIZE)] == ' ')
		put_pxl(&game->frame, x, y, game->scene->c_color);
	else
		put_pxl(&game->frame, x, y, game->scene->f_color);
}

void	put_cirmap(t_game *game, t_vec center, int radius, double angle)
{
	int	i;
	int	j;

	i = center.x - radius;
	while (i <= center.x + radius)
	{
		j = center.y - radius;
		while (j <= center.y + radius)
		{
			if ((i - center.x) * (i - center.x) + (j - center.y) * (j
					- center.y) <= radius * radius)
				put_mappxl(game, i, j, angle);
			j++;
		}
		i++;
	}
}

void	rot_cir(t_game *game, t_vec center, double angle)
{
	center.x += cos(angle) * 135;
	center.y += sin(angle) * 135;
	put_sldcir(game, center, 15, 0x141414);
	put_image_to_image((int *)game->frame.addr, (int *)game->n.addr,
		center.x - 10, center.y - 10);
}

void	put_minimap(t_game *game)
{
	t_vec	center;

	center.x = WIN_W - 200;
	center.y = WIN_H - 200;
	put_sldcir(game, center, 140, 0x141414);
	put_sldcir(game, center, 130, game->scene->f_color);
	put_cirmap(game, center, 130, game->mm_ang);
	rot_cir(game, center, game->mm_ang);
	put_sldcir(game, center, 10, 0x141414);
	put_sldcir(game, center, 8, 0xFFFFFF);
}
