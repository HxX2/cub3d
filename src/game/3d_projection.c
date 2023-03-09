/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_implementetion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:04:26 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/09 08:03:33 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	get_texel(t_game *game, int offset_x, int offset_y, int x)
{
	if (!game->rays[x].is_v_hit)
	{
		if (game->rays[x].is_up)
			return (*(unsigned int *)(game->north.addr + \
				offset_y * game->north.line_length + \
				offset_x * (game->north.bits_per_pixel / 8)));
		else if (game->rays[x].is_down)
			return (*(unsigned int *)(game->south.addr + \
				offset_y * game->south.line_length + \
				offset_x * (game->south.bits_per_pixel / 8)));
	}
	else if (game->rays[x].is_v_hit)
	{
		if (game->rays[x].is_right)
			return (*(unsigned int *)(game->east.addr + \
				offset_y * game->east.line_length + \
				offset_x * (game->east.bits_per_pixel / 8)));
		else if (game->rays[x].is_left)
			return (*(unsigned int *)(game->west.addr + \
				offset_y * game->west.line_length + \
				offset_x * (game->west.bits_per_pixel / 8)));
	}
	return (0);
}

void	texture(t_game *game, int top_pix, int bottom_pix, int x)
{
	int				y;
	int				offset_x;
	int				offset_y;
	int				distance_from_top;
	unsigned int	texel;

	if (game->rays[x].is_v_hit)
		offset_x = (int)game->rays[x].w_hit_y % T_SIZE;
	else
		offset_x = (int)game->rays[x].w_hit_x % T_SIZE;
	y = top_pix;
	while (y < bottom_pix)
	{
		distance_from_top = y + (game->rays[x].wall_height / 2) - (WIN_H / 2);
		offset_y = distance_from_top * \
			((double)T_SIZE / game->rays[x].wall_height);
		texel = get_texel(game, offset_x, offset_y, x);
		put_pxl(&game->frame, x, y, texel);
		y++;
	}
}

void	load_textures(t_game *game)
{
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->scene->no_path,
			&game->north.width, &game->north.height);
	game->north.addr = mlx_get_data_addr(game->north.img,
			&game->north.bits_per_pixel, &game->north.line_length,
			&game->north.endian);
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->scene->so_path,
			&game->south.width, &game->south.height);
	game->south.addr = mlx_get_data_addr(game->south.img,
			&game->south.bits_per_pixel, &game->south.line_length,
			&game->south.endian);
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->scene->we_path,
			&game->west.width, &game->west.height);
	game->west.addr = mlx_get_data_addr(game->west.img,
			&game->west.bits_per_pixel, &game->west.line_length,
			&game->west.endian);
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->scene->ea_path,
			&game->east.width, &game->east.height);
	game->east.addr = mlx_get_data_addr(game->east.img,
			&game->east.bits_per_pixel, &game->east.line_length,
			&game->east.endian);
}

void	project_wall(t_game *game)
{
	int		x;
	int		top_pix;
	int		bottom_pix;
	double	perp_dist;

	load_textures(game);
	x = -1;
	while (++x < N_RAYS)
	{
		game->rays[x].distance_pro = (WIN_W / 2) / tan(FOV / 2);
		perp_dist = game->rays[x].dist * \
			cos(game->rays[x].angle - game->player.rot_ang);
		game->rays[x].projected_wall_height = (T_SIZE / perp_dist) * \
			game->rays[x].distance_pro;
		game->rays[x].wall_height = (int)game->rays[x].projected_wall_height;
		top_pix = (WIN_H / 2) - (game->rays[x].wall_height / 2);
		if (top_pix < 0)
			top_pix = 0;
		bottom_pix = (WIN_H / 2) + (game->rays[x].wall_height / 2);
		if (bottom_pix > WIN_H)
			bottom_pix = WIN_H;
		texture(game, top_pix, bottom_pix, x);
	}
}
