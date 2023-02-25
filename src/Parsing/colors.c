/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 00:59:20 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/25 04:14:32 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	rgb_hexa(t_scene *cub, char *str, char *tmp, int i)
{
	if (ft_strcmp(str, "F"))
	{
		if (i == 0)
		{
			cub->f_color = 0;
			cub->f_color += (ft_atoi(tmp) & (0xFF)) << 16;
		}
		if (i == 1)
			cub->f_color += (ft_atoi(tmp) & (0xFF)) << 8;
		if (i == 2)
			cub->f_color += (ft_atoi(tmp) & (0xFF));
	}
	if (ft_strcmp(str, "C"))
	{
		if (i == 0)
		{
			cub->c_color = 0;
			cub->c_color += (ft_atoi(tmp) & (0xFF)) << 16;
		}
		if (i == 1)
			cub->c_color += (ft_atoi(tmp) & (0xFF)) << 8;
		if (i == 2)
			cub->c_color += (ft_atoi(tmp) & (0xFF));
	}
}

void	clamp_digit(char **rgb_str, char *tmp, int i)
{
	if (!is_digit(tmp))
	{
		ft_rwipe(rgb_str, 2);
		free(tmp);
		exit(printf("Error: An rgb_color contains a None digit char!\n"));
	}
	if (ft_atoi(rgb_str[i]) < 0 || ft_atoi(rgb_str[i]) > 255)
	{
		ft_rwipe(rgb_str, 2);
		free(tmp);
		exit(printf("Error: Out of range\n"));
	}
}

int	valid_color(t_scene *cub, char *str, char *color_line)
{
	char	**rgb_str;
	char	*tmp;
	int		i;

	i = 0;
	if (ft_count(color_line, ',') != 2)
		exit(printf("Error: Wrong number of commas!\n"));
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
		exit(printf("Error: Line -%s- not found\n", str));
	line = ft_strtrim(cub->scene[y], " ");
	if (ft_strncmp(line, str, 1))
	{
		free (line);
		exit(printf("Error: There isn't only white spaces before -%s-\n", str));
	}
	color_line = ft_substr(line, 1, ft_strlen(line) - 1);
	free(line);
	if (white_space(*color_line))
	{
		free (color_line);
		exit(printf("Error: No space after \"%s\"!\n", str));
	}
	valid_color(cub, str, color_line);
	return (0);
}
