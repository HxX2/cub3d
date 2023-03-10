/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 20:35:23 by gkarib            #+#    #+#             */
/*   Updated: 2023/03/09 16:58:50 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	red_cross(void)
{
	exit(1);
}

int	unclick_mouse(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		key_release(KEY_LEFT, game);
	else if (button == RIGHT_CLICK)
		key_release(KEY_RIGHT, game);
	return (0);
}

int	click_mouse(int button, int x, int y, t_game *game)
{
	(void)x;
	(void)y;
	if (button == LEFT_CLICK)
		key_press(KEY_LEFT, game);
	else if (button == RIGHT_CLICK)
		key_press(KEY_RIGHT, game);
	return (0);
}
