/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:01:15 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/21 15:38:48 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	valid_file_xpm(t_scene *cub, char *str, char *path)
{
	int	x;

	x = 0;
	if (!valid_extension(path + x, ".xpm"))
	{
		free(path);
		return (printf("Extension of -%s- file Not Valid!\n", str));
	}
	if (!ft_strcmp(str, "NO"))
		xpm_file_opened(str, path, &cub->no);
	else if (!ft_strcmp(str, "SO"))
		xpm_file_opened(str, path, &cub->so);
	else if (!ft_strcmp(str, "WE"))
		xpm_file_opened(str, path, &cub->we);
	else if (!ft_strcmp(str, "EA"))
		xpm_file_opened(str, path, &cub->ea);
	return (0);
}

int	ft_directions(t_scene *cub, char *str)
{
	char	*line;
	char	*path;
	int		y;

	y = search_line(cub, str);
	if (y == -1)
		return (printf("Line -%s- not found", str));
	line = ft_strtrim(cub->scene[y], " ");
	if (ft_strncmp(line, str, 2))
	{
		free (line);
		return (printf("There isn't only white spaces before -%s-", str));
	}
	path = ft_substr(line, 2, ft_strlen(line) - 2);
	free(line);
	if (white_space(*path))
	{
		free (path);
		return (printf("No space after \"%s\"!\n", str));
	}
	if (valid_file_xpm(cub, str, path))
		return (1);
	return (0);
}

void	clamp_digit(char **rgb_str, char *tmp, int i)
{
	if (!is_digit(tmp))
	{
		ft_rwipe(rgb_str, 2);
		free(tmp);
		exit(printf("An rgb_color contains a None digit char!"));
	}
	if (ft_atoi(rgb_str[i]) < 0 || ft_atoi(rgb_str[i]) > 255)
	{
		ft_rwipe(rgb_str, 2);
		free(tmp);
		exit(printf("out of range"));
	}
}

int	valid_color(t_scene *cub, char *str, char *color_line)
{
	char	**rgb_str;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_count(color_line, ',') != 2)
		return (printf("Wrong number of commas!"));
	rgb_str = ft_split(color_line, ',');
	free(color_line);
	while (rgb_str[i])
	{
		tmp = ft_strtrim(rgb_str[i], " ");
		clamp_digit(rgb_str, tmp, i);
		rgb_hexa(cub, str, tmp, i);
		i++;
		free(tmp);
	}
	ft_rwipe(rgb_str, 2);
	return (0);
}

int	ft_colors(t_scene *cub, char *str)
{
	char	*line;
	char	*color_line;
	int		y;

	y = search_line(cub, str);
	if (y == -1)
		return (printf("Line -%s- not found", str));
	line = ft_strtrim(cub->scene[y], " ");
	if (ft_strncmp(line, str, 1))
	{
		free (line);
		return (printf("There isn't only white spaces before -%s-", str));
	}
	color_line = ft_substr(line, 1, ft_strlen(line) - 1);
	free(line);
	if (white_space(*color_line))
	{
		free (color_line);
		return (printf("No space after \"%s\"!\n", str));
	}
	valid_color(cub, str, color_line);
	return (0);
}
