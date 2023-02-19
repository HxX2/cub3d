/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 03:17:38 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/19 21:28:09 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>
# include "mlx.h"
# include "src/libft/libft.h"

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
# define T_SIZE 64

typedef struct s_vec
{
	int		x;
	int		y;
}			t_vec;

typedef struct s_player
{
	double		x;
	double		y;
	int			turn_dir;
	int			walk_dir;
	double		rot_ang;
	double		move_speed;
	double		rot_speed;
}			t_player;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_scene
{
	char	**scene;
	char	**map;

	int		player_x;
	int		player_y;
	char	player_position;
	
	int		no;
	int		so;
	int		we;
	int		ea;

	int		h_map;
	int		w_map;

}	t_scene;

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
	t_scene		*scene;
}		t_game;

// ======================PARSING:======================

bool	white_space(char c);
bool	valid_character(char c);
int		ft_ptrlen(char **ptr);
int		ft_count(char *str, char c);
bool	is_digit(char	*str);


bool	valid_extension(char *file_name, char *extension);
int		valid_path(char *path);
int		check_character(t_scene *cub);
int		check_direction(t_scene *cub);
int		white_space_surrounded_by_walls(t_scene *cub);
int		surrounded_by_walls(t_scene *cub);
void	import_scene(int fd, t_scene *cub);
void	import_map(t_scene *cub);
void	player_coordinates(t_scene *cub);

int		search_line(t_scene *cub, char *str);

int		ft_directions(t_scene *cub, char *str);
int		ft_colors(t_scene *cub, char *str);

int		parse_map(char *str, t_scene *cub);

// ======================GAME:======================

int		key_press(int keycode, void *param);
int		key_release(int keycode, void *param);
void	init_game(t_game *game);
void	init_player(t_game *game);
void	ft_rwipe(void *ptr, int plvl);
int		render_frame(t_game *game);
void	*ft_xalloc(size_t n);

void	put_pxl(t_data *data, int x, int y, int color);
void	put_sldrect(t_game *game, int x0, int y0, int x1, int y1, int color);
void	put_sldcir(t_game *game, int x, int y, int radius, int color);
void	put_line(t_game *game, int x, int y, double angle, int size, int color);

#endif