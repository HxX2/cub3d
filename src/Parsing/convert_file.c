/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:46:55 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/05 00:31:18 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	split_scene(t_scene *cub, char *map)
{
	cub->scene = ft_split(map, '\n');
	free(map);
	if (!ft_ptrlen(cub->scene))
		exit (printf("Empty File!"));
}

void	import_scene(int fd, t_scene *cub)
{
	int		eof;
	char	*buffer;
	char	*tmp;
	char	*map;

	buffer = malloc(sizeof(char) * 1025);
	if (!buffer)
		exit(printf("Error: allocattion failed!\n"));
	eof = 1;
	map = ft_strdup("");
	while (eof)
	{
		eof = read(fd, buffer, 1024);
		if (eof == -1)
			exit (printf("Error related with reading the map\n"));
		buffer[eof] = 0;
		tmp = map;
		map = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!map)
			return ;
	}
	free(buffer);
	check_new_line(map);
	split_scene(cub, map);
}

char	*clean_line(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	while (!white_space(str[len]))
	{
		len--;
		if (len == 0)
			break ;
	}
	return (ft_substr(str, i, len + 1));
}

void	fill_line(t_scene *cub)
{
	char	*tmp;
	int		y;

	y = 0;
	while (cub->map[y])
	{
		while ((int)ft_strlen(cub->map[y]) < cub->w_map)
		{
			tmp = cub->map[y];
			cub->map[y] = ft_strjoin(tmp, " ");
			free (tmp);
		}
		y++;
	}
}

void	import_map(t_scene *cub)
{
	int	y;
	int	i;

	y = 6;
	i = 0;
	cub->map = malloc(sizeof(char *) * ft_ptrlen(cub->scene) - y + 1);
	if (!cub->map)
		exit(printf("Error: allocattion failed!\n"));
	while (y < ft_ptrlen(cub->scene))
	{
		cub->map[i] = clean_line(cub->scene[y]);
		y++;
		i++;
	}
	cub->map[i] = NULL;
	cub->h_map = ft_ptrlen(cub->map);
	cub->w_map = 0;
	y = 0;
	while (y < cub->h_map)
	{
		if (cub->w_map < (int)ft_strlen(cub->map[y]))
			cub->w_map = (int)ft_strlen(cub->map[y]);
		y++;
	}
	fill_line(cub);
}
