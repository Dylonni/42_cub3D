/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:28:02 by dylan             #+#    #+#             */
/*   Updated: 2024/02/13 19:27:24 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_backwards(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_x * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x + data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y - data->player.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player.pos_x - data->player.dir_y * MOVESPEED;
	new_y = data->player.pos_y + data->player.dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

int	move(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player.go_y == 1)
		moved += move_forward(data);
	if (data->player.go_y == -1)
		moved += move_backwards(data);
	if (data->player.go_x == -1)
		moved += move_left(data);
	if (data->player.go_x == 1)
		moved += move_right(data);
	if (data->player.rotate != 0)
		moved += rotate(data, data->player.rotate);
	return (moved);
}
