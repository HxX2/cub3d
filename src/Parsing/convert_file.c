/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:46:55 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:21:46 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void import_map(int fd, t_scene *cub)
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
	free(map);

}
