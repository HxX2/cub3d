/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:01:15 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/19 21:27:57 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"


int	valid_file_xpm(t_scene *cub, char *str, char *path)
{
	int	x;

	x = 0;
	while (!white_space(path[x]))
		x++;
	if (!valid_extension(path + x, ".xpm"))
	{
		free(path);
		return (printf("Extension of -%s- file Not Valid!\n", str));
	}
	if (ft_strcmp(str, "NO"))
		cub->no = valid_path(path + x);
	else if (ft_strcmp(str, "SO"))
		cub->so = valid_path(path + x);
	else if (ft_strcmp(str, "WE"))
		cub->we = valid_path(path + x);
	else if (ft_strcmp(str, "EA"))
		cub->ea = valid_path(path + x);
	free(path);
	if (!cub->no || !cub->so || !cub->we || !cub->ea)
		return (printf("File -%s- couldn't open!\n", str));
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

int	valid_color(char *color_line)
{
	char	**rgb_str;
	char	**rgb_num;
	int	i;

	i = 0;
	if (ft_count(color_line, ',') != 2)
		return(printf("Wrong number of commas!"));
	rgb_str = ft_split(color_line, ',');
	free(color_line);
	rgb_num = malloc(sizeof(char *) * ft_ptrlen(rgb_str) + 1);
	
	//? why does it segfault ?
		// printf("str = %d\n", ft_ptrlen(rgb_str));
		// printf("num = %d\n", ft_ptrlen(rgb_num));
	while(rgb_str[i])
	{
		rgb_num[i] = ft_strtrim(rgb_str[i], " ");
		i++;
	}
	// rgb_num[i] = NULL;
	//* leaks to handle 

	// i = 0;
	// while (rgb_num[i])
	// {
	// 	if (!is_digit(rgb_num[i]))
	// 	{
	// 		// // * leaks here too
	// 		// while (rgb_num[i])
	// 		// {
	// 		// 	free(rgb_str[i]);
	// 		// 	i++;
	// 		// }
	// 		// free (rgb_num);
	// 		return (printf("An rgb_color contains a None digit char!"));
	// 	}
	// 	if (ft_atoi(rgb_num[i]) < 0 || ft_atoi(rgb_num[i]) > 255)
	// 		return (printf("out of range"));
	// 	i++;	
	// }
	// i = 0;
	// while (rgb_str[i])
	// {
	// 	free(rgb_str[i]);
	// 	i++;
	// }
	// free (rgb_str);
	return(0);
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
	if (valid_color(color_line))
		return (1);
	// free (color_line);
	return (0);
}