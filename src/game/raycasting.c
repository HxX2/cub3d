/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:17:23 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/25 05:28:55 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ray_collision(t_game *game, double dx, double dy, int x, int y)
{
	int p0;
	int p1;
	int p2;

	p0 = game->scene->map[(int)((dy + y) / T_SIZE)][(int)((dx + x)/ T_SIZE)] != '1';
	p1 = (game->scene->map[(int)(((dy + y) - 1) / T_SIZE)][(int)(((dx + x) + 1)/ T_SIZE)] != '1' && game->scene->map[(int)(((dy + y) + 1) / T_SIZE)][(int)(((dx + x) - 1)/ T_SIZE)] != '1');
	p2 = (game->scene->map[(int)(((dy + y) - 1) / T_SIZE)][(int)(((dx + x) - 1)/ T_SIZE)] != '1'  && game->scene->map[(int)(((dy + y) + 1) / T_SIZE)][(int)(((dx + x) + 1)/ T_SIZE)] != '1');

	return (p0 && p1 && p2);
}

void	shoot_ray(t_game *game, int x, int y, double angle, int color)
{
	int i;
	double dx;
	double dy;

    i = 1;
    dx = cos(angle) * i;
    dy = sin(angle) * i;
    while (ray_collision(game, dx,dy,x,y))
	{
        i++;
        dx = cos(angle) * i;
        dy = sin(angle) * i;
		put_pxl(&game->frame, dx+x, dy+y, color);
    }
}

void	shoot_rays(t_game *game, int x, int y, double angle, int color)
{ 
	double o_angle;
	int i;

	angle -= (30 * (M_PI / 180));
	o_angle = angle;
	i = 0;
	while(angle <= o_angle + (60 * (M_PI / 180)))
	{
		shoot_ray(game, x, y, angle, color);
		angle += ((M_PI / (360*6)));
		i++;
	}
	printf("%d\n", i);
}