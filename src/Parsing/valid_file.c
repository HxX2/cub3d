/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:45:51 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 01:49:05 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	valid_extension(char *file_name, char *extension)
{
	if (ft_strlen(file_name) > 4
		&& !ft_strncmp(&file_name[ft_strlen(file_name) - 4], extension, 4))
		return (1);
	return (0);
}

int	valid_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (0);
	return (fd);
}

int	search_line(t_scene *cub, char *str)
{
	int		y;

	y = 0;
	while (y < 6)
	{
		if (ft_strstr(cub->scene[y], str))
			return (y);
		y++;
	}
	return (-1);
}
