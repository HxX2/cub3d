/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 01:43:29 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/17 23:21:46 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	find_wall_delimiter(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '1' && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
// #include <stdio.h>
// #include <string.h>

// void extract_lines_before_delimiter(char arr[][100], char delimiter[], char output_arr[][100]) {
//     int i, j;
//     for (i = 0; i < sizeof(arr); i++) {
//         if (strstr(arr[i], delimiter) != NULL) {
//             break;
//         }
//         strcpy(output_arr[i], arr[i]);
//     }
// }

// int main() {
//     char my_array[][100] = {
//         "apple banana cherry",
//         "date elderberry fig",
//         "grape honeydew kiwi",
//         "lemon melon orange",
//         "peach quince strawberry",
//         "tangerine watermelon peach",
//         "lemon lime orange"
//     };
//     char output_array[100][100];
//     extract_lines_before_delimiter(my_array, "lemon", output_array);
//     int i, j;
//     for (i = 0; i < sizeof(output_array); i++) {
//         if (strlen(output_array[i]) == 0) {
//             break;
//         }
//         for (j = 0; j < sizeof(output_array[i]); j++) {
//             printf("%c", output_array[i][j]);
//         }
//         printf("\n");
//     }
//     return 0;
// }

// char *findSubstring(char* str, char* substr)
// {
// 	char	*found;
// 	int		index;
// 	int		i;
	
// 	index = 0;
// 	i = 0;
// 	found = ft_strstr(str, substr);
// 	if (found)
// 	{
// 		index = (int)(found - str);
// 		while (i < index)
// 		{
// 			if (white_space(found[i]))
// 				return (NULL);
// 			i++;
// 		}
// 	}
// 	else
// 		return (NULL);
// 	return (found);
// }

int findSubstring(const char* str, const char* substr)
{
    const char* found = strstr(str, substr);

    if (found)
        return (int)(found - str);
    else
        return -1;
}

int	North_texture(t_scene *cub)
{
	char	*line;
	char	*path;
	int		x;
	int		y;
	
	x = 0;
	y = search_line(cub, "NO");
	if (y == -1)
		return (printf("Line -NO- not found"));
	line = skiping_white_spaces(cub->scene[y], "NO");
	if (ft_strncmp(line, "NO", 2))
		return (printf("There isn't only white spaces before -NO-"));
	path = ft_substr(line, 2, ft_strlen(line) - 2);
	free(line);
	if (white_space(*path))
		return (printf("No space after \"NO\"!\n"));
	while (!white_space(path[x]))
		x++;
	if (!valid_extension(path + x, ".xpm"))
		return (printf("Extension of NO file Not Valid!\n"));
	cub->texture->no = valid_path(path + x);
	free(path);
	if (!cub->texture->no)
		return (printf("File couldn't open!\n"));
	return (0);
}

void	check_texture_and_color(t_scene *cub)
{
	int	y;

	y = 0;
	while (cub->scene[y])
	{
		if (find_wall_delimiter(cub->scene[y]))
		{
			// printf ("found del: y = %d => %s\n", y, cub->scene[y]);
			break ;
		}
		y++;
	}
	if (y == 6)
	{
		North_texture(cub);
		// South_texture();
		// West_texture();
		// East_texture();
	}
	// else
		// textures are missing
}


int	parse_map(char *str, t_scene *cub)
{
	// int fd;
	
	(void) cub;
	if (!valid_extension(str, ".cub"))
		return (printf("Extension Not Valid!\n"));
	// fd = valid_path(str);
	// if (!fd)
	// 	return (printf("File couldn't open!\n"));


	// import_map(fd, cub);

	
	// int i = 0;
	// while (cub->scene[i])
	// {
	// 	printf("%s\n", cub->scene[i]);
	// 	i++;
	// }
	
	// check_texture_and_color(cub);
	
	// if (!check_character(cub))
	// 	return(printf("Not a Valid Character found!"));
	// if (check_direction(cub) != 1)
	// 	return(printf("Starting Position Duplicated or not Found!"));
	// if (!surrounded_by_walls(cub))
	// 	return(printf("Not Surrounded by Walls!"));
	
	
	return (0);
}