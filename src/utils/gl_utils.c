/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:36:29 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 14:20:19 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_image_to_image(int *big_img, int *small_img, int x, int y)
{
	int	i;
	int	j;
	int	s_i;
	int	b_i;

	i = 0;
	while (i < 20)
	{
		j = 0;
		while (j < 20)
		{
			s_i = i * 20 + j;
			b_i = (y + i) * WIN_W + (x + j);
			if ((x + j) >= WIN_W || (y + i) >= WIN_H)
			{
				j++;
				continue ;
			}
			big_img[b_i] = small_img[s_i];
			j++;
		}
		i++;
	}
}

void	rot_pxl(int *x, int *y, double angle)
{
	double	tx;
	double	ty;

	tx = *x - (WIN_W - 200);
	ty = *y - (WIN_H - 200);
	*x = (int)round(tx * cos(angle) - ty * sin(angle));
	*y = (int)round(tx * sin(angle) + ty * cos(angle));
	*x += (WIN_W - 200);
	*y += (WIN_H - 200);
}

int	in_collision(t_game *game, double dx, double dy)
{
	int	p0;
	int	p1;
	int	p2;

	p0 = game->scene->map[(int)((game->player.y + dy)
			/ T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';
	p1 = game->scene->map[(int)((game->player.y + dy)
			/ T_SIZE)][(int)(game->player.x / T_SIZE)] != '1';
	p2 = game->scene->map[(int)((game->player.y)
			/ T_SIZE)][(int)((game->player.x + dx) / T_SIZE)] != '1';
	return (p0 && p1 && p2);
}

void	put_cf(t_game *game)
{
	t_vec	c_start;
	t_vec	c_end;
	t_vec	f_start;
	t_vec	f_end;

	c_start.x = 0;
	c_start.y = 0;
	c_end.x = WIN_W;
	c_end.y = WIN_H / 2;
	put_sldrectw(game, c_start, c_end, game->scene->c_color);
	f_start.x = 0;
	f_start.y = WIN_H / 2;
	f_end.x = WIN_W;
	f_end.y = WIN_H;
	put_sldrectw(game, f_start, f_end, game->scene->f_color);
}
