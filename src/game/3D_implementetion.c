/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3D_implementetion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 00:04:26 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/04 03:05:36 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

unsigned int	get_texel(t_game *game, int offset_x, int offset_y)
{
	if (game->rays->is_h_hit)
	{
		if (game->rays->is_up)
			return(*(unsigned int *)(game->north.addr + offset_y * game->north.line_length
				+ offset_x * (game->north.bits_per_pixel / 8)));
		else if (game->rays->is_down)
			return(*(unsigned int *)(game->south.addr + offset_y * game->south.line_length
				+ offset_x * (game->south.bits_per_pixel / 8)));
	}
	else if (game->rays->is_v_hit)
	{
		if (game->rays->is_right)
			return(*(unsigned int *)(game->east.addr + offset_y * game->east.line_length
				+ offset_x * (game->east.bits_per_pixel / 8)));
		else if (game->rays->is_left)
			return(*(unsigned int *)(game->west.addr + offset_y * game->west.line_length
				+ offset_x * (game->west.bits_per_pixel / 8)));
	}
	return (0);
}

void pikuma_texture(t_game *game, int top_pix, int bottom_pix, int x, int wall_strip_height)
{
	int	offset_x;
	int	offset_y;
	unsigned int texel;
	
	if (game->rays->is_v_hit)
		offset_x = (int)game->rays[x].w_hit_y % T_SIZE;
	else
		offset_x = (int)game->rays[x].w_hit_x % T_SIZE;
	for (int y = top_pix; y < bottom_pix; y++)
	{

		int distance_from_top = y + (wall_strip_height / 2) - (WIN_H / 2);
		offset_y = distance_from_top * ((double)T_SIZE / wall_strip_height);
		if (offset_y < 0)
			offset_y = 0;
		texel = get_texel(game, offset_x, offset_y);
		// texel = *(unsigned int *)(game->east.addr + (offset_y * game->east.line_length) + (offset_x * (game->east.bits_per_pixel / 8)));
		put_pxl(&game->frame, x, y, texel);
	}
}


void	get_mlx_data(t_game *game)
{
	int w_no = 0;
	int h_no = 0;
	
	int w_so = 0;
	int h_so = 0;
	
	int w_we = 0;
	int h_we = 0;
	
	int w_ea = 0;
	int h_ea = 0;
	
	game->north.img = mlx_xpm_file_to_image(game->mlx, game->scene->no_path, &w_no, &h_no);
	game->north.addr = mlx_get_data_addr(game->north.img, &game->north.bits_per_pixel, &game->north.line_length, &game->north.endian);
	
	game->south.img = mlx_xpm_file_to_image(game->mlx, game->scene->so_path, &w_so, &h_so);
	game->south.addr = mlx_get_data_addr(game->south.img, &game->south.bits_per_pixel, &game->south.line_length, &game->south.endian);
	
	game->west.img = mlx_xpm_file_to_image(game->mlx, game->scene->we_path, &w_we, &h_we);
	game->west.addr = mlx_get_data_addr(game->west.img, &game->west.bits_per_pixel, &game->west.line_length, &game->west.endian);
	
	game->east.img = mlx_xpm_file_to_image(game->mlx, game->scene->ea_path, &w_ea, &h_ea);
	game->east.addr = mlx_get_data_addr(game->east.img, &game->east.bits_per_pixel, &game->east.line_length, &game->east.endian);
}

void	project_wall(t_game *game)
{
	double	perp_dist; // correct the fishbow effect
	int		x;
	int		wall_strip_height;
	int		top_pix;
	int		bottom_pix;

	get_mlx_data(game);
	
	x = -1;
	while (++x < N_RAYS)
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
		pikuma_texture(game, top_pix, bottom_pix, x, wall_strip_height);
	}
	// mlx_put_image_to_window(game->mlx, game->win, game->north.img, 0, 0);
}
