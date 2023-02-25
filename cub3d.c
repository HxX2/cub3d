/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:37:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/02/25 04:23:33 by gkarib           ###   ########.fr       */
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
			return (1);
		// system("leaks cub3D");
	}
	else
		return (printf("Wrong number of argument!\n"));
	// init_game(&game);
	// init_player(&game);
	// mlx_hook(game.win, EVENT_KEY_PRESS, 0, key_press, &game);
	// mlx_hook(game.win, EVENT_KEY_RELEASE, 0, key_release, &game);
	// mlx_loop_hook(game.mlx, render_frame, &game);
	// mlx_loop(game.mlx);
	// // ft_rwipe(game.scene->scene, 2);

	return (0);
}