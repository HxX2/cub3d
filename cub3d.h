/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:17:38 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/14 17:05:18 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "mlx.h"

# define EVENT_CLOSE 17
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15

typedef struct s_player
{
	double		x;
	double		y;
	int		turn_dir;
	int		walk_dir;
	double	rot_ang;
	double	move_speed;
	double	rot_speed;
}			t_player;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		*mapfile;
	char		**map;
	int			mapw;
	int			maph;
	t_data		frame;
	t_player	player;
}		t_game;

#endif