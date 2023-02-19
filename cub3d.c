/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlafou <zlafou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:37:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/19 21:04:59 by zlafou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	game.scene = ft_xalloc(sizeof(t_scene));
    if (ac == 2)
    {
        if (parse_map(av[1], game.scene))
            return(1);
    }
    else
        return (printf("Wrong number of argument!\n"));
	// ft_rwipe(game.scene->scene, 2);

	// init_game(&game);
	// init_player(&game);
	// mlx_hook(game.win, EVENT_KEY_PRESS, 0, key_press, &game);
	// mlx_hook(game.win, EVENT_KEY_RELEASE, 0, key_release, &game);
	// mlx_loop_hook(game.mlx, render_frame, &game);

	return (0);
}


// int    main(int ac, char **av)
// {
//     (void) ac;
//     int x;
//     int    y;

//     x = 0;
//     y = 0;
//     t_Cub *cub = malloc(sizeof(t_Cub));
//     if (ac == 2)
//     {
//         if (parse_map(av[1], cub))
//             return(1);
//     }
//     else
//         return (printf("Wrong number of argument!\n"));
//     while (cub->scene[y])
//     {
//         free(cub->scene[y]);
//         y++;
//     }
//     free (cub->scene);
//     // int    i;
//     // i = 0;
//     // while (cub->map[i])
//     // {
//     //     free(cub->map[i]);
//     //     y++;
//     // }
//     // free (cub->map);
//     free(cub);
//     system("leaks Cub3D");
//     return (0);
// }