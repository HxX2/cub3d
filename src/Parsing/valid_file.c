/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:45:51 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:21:46 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

bool	valid_extension(char *file_name, char *extension)
{
	int	len;

	len = ft_strlen(file_name);
	while (!white_space(file_name[len - 1]))
		len--;
	if (len > 4 && !ft_strncmp(&file_name[len - 4], extension, 4))
		return (1);
	return (0);
}

int	valid_path(char *path)
{
	int	fd;
	int	len;

	len = ft_strlen(path);
	while (!white_space(path[len - 1]))
		len--;
	path = path - len;
	
	if ((fd = open(path, O_RDONLY)) < 0)
		return (0);
	// printf("valid path: fd = %d\n", fd);
	return (fd);
}

int	search_line(t_scene *cub, char *str)
{
	int		y;
	
	y = 0;
	while (y < 6)
	{
		if (ft_strstr(cub->scene[y], str)) // line where no is 
			return (y);
		y++;
	}
	return (-1);
}

char	*skiping_white_spaces(char	*str, char *direction)
{
	int	i;

	i = 0;
	while (i < findSubstring(str, direction))
	{
		if (white_space(str[i]))
			break;
		i++;
	}
	return (ft_substr(str, i, ft_strlen(str) - i));
}
