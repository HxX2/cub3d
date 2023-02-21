/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:46:55 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 15:40:31 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	ft_ptrlen(char **ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (0);
	while (ptr[i])
		i++;
	return (i);
}

void	check_new_line(char *map)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (map[i])
	{
		if (map[i] == '1')
		{
			i++;
			if (map[i] == '\n')
			{
				while (map[i] == '\n')
				{
					i++;
					flag++;
				}
			}
			if (map[i] == '1' && flag > 1)
				exit(printf("more than 1 new line found"));
		}
		flag = 0;
		i++;
	}
}

void	import_scene(int fd, t_scene *cub)
{
	int		eof;
	char	*buffer;
	char	*tmp;
	char	*map;

	buffer = malloc(sizeof(char) * 1025);
	eof = 1;
	map = ft_strdup("");
	while (eof)
	{
		eof = read(fd, buffer, 1024);
		buffer[eof] = 0;
		tmp = map;
		map = ft_strjoin(tmp, buffer);
		free(tmp);
		if (!map)
			return ;
	}
	free(buffer);
	check_new_line(map);
	cub->scene = ft_split(map, '\n');
	if (!ft_ptrlen(cub->scene))
		exit (printf("Empty File!"));
	free(map);
}

void	import_map(t_scene *cub)
{
	int	y;
	int	i;

	y = 6;
	i = 0;
	cub->map = malloc(sizeof(char *) * ft_ptrlen(cub->scene) - y + 1);
	while (y < ft_ptrlen(cub->scene))
	{
		cub->map[i] = cub->scene[y];
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
}
