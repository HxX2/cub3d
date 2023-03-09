/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:27:43 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 11:06:55 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	put_pxl(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x > (WIN_W) || y < 0 || y > (WIN_H))
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	put_sldrectw(t_game *game, t_vec start, t_vec end, int color)
{
	int	i;
	int	j;

	j = start.y;
	while (j < end.y)
	{
		i = start.x;
		while (i < end.x)
		{
			put_pxl(&game->frame, i, j, color);
			i++;
		}
		j++;
	}
}

void	put_sldcir(t_game *game, t_vec center, int radius, int color)
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
				put_pxl(&game->frame, i, j, color);
			j++;
		}
		i++;
	}
}
