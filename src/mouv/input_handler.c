/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 18:32:22 by mba               #+#    #+#             */
/*   Updated: 2024/02/13 16:45:03 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/* a behavior when the corresponding key is pressed
Keys are defined in cub3d.h*/

static int	on_key_press(int key, t_data *data)
{
	if (key == KEY_FORWARD)
		data->player.go_y = 1;
	if (key == KEY_BACK)
		data->player.go_y = -1;
	if (key == KEY_RIGHT)
		data->player.go_x = 1;
	if (key == KEY_LEFT)
		data->player.go_x = -1;
	if (key == KEY_ARR_L)
		data->player.rotate -= 1;
	if (key == KEY_ARR_R)
		data->player.rotate += 1;
	if (key == KEY_ESC)
		exit_game(data);
	return (0);
}

static int	on_key_release(int key, t_data *data)
{
	if (key == KEY_FORWARD && data->player.go_y == 1)
		data->player.go_y = 0;
	if (key == KEY_BACK && data->player.go_y == -1)
		data->player.go_y = 0;
	if (key == KEY_LEFT && data->player.go_x == -1)
		data->player.go_x += 1;
	if (key == KEY_RIGHT && data->player.go_x == 1)
		data->player.go_x -= 1;
	if (key == KEY_ARR_L && data->player.rotate <= 1)
		data->player.rotate = 0;
	if (key == KEY_ARR_R && data->player.rotate >= -1)
		data->player.rotate = 0;
	if (key == KEY_ESC)
		exit_game(data);
	return (0);
}

void	input_handler(t_data *data)
{
	mlx_hook(data->win, 33, 0L, exit_game, data);
	mlx_hook(data->win, 02, 1L << 0, on_key_press, data);
	mlx_hook(data->win, 03, 1L << 1, on_key_release, data);
}
