/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:27:43 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/19 20:15:13 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_sldrect(t_game *game, int x0, int y0, int x1, int y1, int color)
{
	int	x;
	int	y;

	y = y0;
	while (y < y1 + T_SIZE)
	{
		x = x0;
		while (x < x1 + T_SIZE)
		{
			put_pxl(&game->frame, x, y, color);
			x++;
		}
		y++;
	}
}

void	put_sldcir(t_game *game, int x, int y, int radius, int color)
{
	int	i;
	int	j;

	i = x - radius;
	while (i <= x + radius)
	{
		j = y - radius;
		while (j <= y + radius)
		{
			if ((i - x) * (i - x) + (j - y) * (j - y) <= radius * radius)
				put_pxl(&game->frame, i, j, color);
			j++;
		}
		i++;
	}
}

void	put_line(t_game *game, int x, int y, double angle,int size, int color)
{
	int i;
	int lx;
	int ly;

	i = 1;
	while (i <= size)
	{
		lx = x + cos(angle);
		ly = y + sin(angle);
		put_pxl(&game->frame, lx, ly, color);
	}
}