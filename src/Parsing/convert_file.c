/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:46:55 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/19 21:25:21 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

//! seg fault (import scene: if scene is empty)
//! seg fault (import map: getting the longest line)

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
	cub->scene = ft_split(map, '\n');
	
	//* seg fault 
	// if (!ft_ptrlen(cub->map))
	// 	exit (0);
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
	
// *seg fault
	// printf("ptrlen == %d\n", cub->h_map);
	// y = 0;
	// while (y < cub->h_map)
	// {
		
	// 	if ((ft_strlen(cub->map[y]) >= ft_strlen(cub->map[y + 1])) && cub->map[y] && cub->map[y + 1])
	// 		cub->w_map = ft_strlen(cub->map[y]);
	// 		// printf("worked");
	// 	y++;
	// 	printf("line %d= %s\n", y, cub->map[y]);
	// }
}
