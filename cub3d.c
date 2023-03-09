/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 20:37:05 by zlafou            #+#    #+#             */
/*   Updated: 2023/03/09 17:06:22 by gkarib           ###   ########.fr       */
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
	}
	else
		return (printf("Wrong number of argument!\n"));
	init_game(&game);
	init_player(&game);
	mlx_hook(game.win, EVENT_KEY_PRESS, 0, key_press, &game);
	mlx_hook(game.win, EVENT_KEY_RELEASE, 0, key_release, &game);
	mlx_hook(game.win, ON_MOUSEDOWN, 0, click_mouse, &game);
	mlx_hook(game.win, ON_MOUSEUP, 0, unclick_mouse, &game);
	mlx_loop_hook(game.mlx, render_frame, &game);
	mlx_hook(game.win, EVENT_CLOSE, 0, red_cross, 0);
	mlx_loop(game.mlx);
	return (0);
}
