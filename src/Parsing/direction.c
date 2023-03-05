/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:01:15 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/05 00:31:44 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	xpm_file_opened(char *str, char *path, char **dir)
{
	int	x;

	x = 0;
	while (!white_space(path[x]))
		x++;
	if (!valid_path(path + x))
	{
		free(path);
		exit(printf("Error: File -%s- couldn't open!\n", str));
	}
	*dir = ft_substr(path, x, ft_strlen(path));
	free(path);
}

int	valid_file_xpm(t_scene *cub, char *str, char *path)
{
	int	x;

	x = 0;
	if (!valid_extension(path + x, ".xpm"))
	{
		free(path);
		exit(printf("Error: Extension of -%s- file Not Valid!\n", str));
	}
	if (!ft_strcmp(str, "NO"))
		xpm_file_opened(str, path, &cub->no_path);
	else if (!ft_strcmp(str, "SO"))
		xpm_file_opened(str, path, &cub->so_path);
	else if (!ft_strcmp(str, "WE"))
		xpm_file_opened(str, path, &cub->we_path);
	else if (!ft_strcmp(str, "EA"))
		xpm_file_opened(str, path, &cub->ea_path);
	return (0);
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

int	ft_directions(t_scene *cub, char *str)
{
	char	*line;
	char	*path;
	int		y;

	y = search_line(cub, str);
	if (y == -1)
		exit(printf("Error: Line -%s- not found\n", str));
	line = ft_strtrim(cub->scene[y], " ");
	if (ft_strncmp(line, str, 2))
	{
		free (line);
		exit(printf("Error: There isn't only white spaces before -%s-\n", str));
	}
	path = ft_substr(line, 2, ft_strlen(line) - 2);
	free(line);
	if (white_space(*path))
	{
		free (path);
		exit(printf("Error: No space after \"%s\"!\n", str));
	}
	if (valid_file_xpm(cub, str, path))
		return (1);
	return (0);
}
