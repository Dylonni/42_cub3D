/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 17:41:07 by dylan             #+#    #+#             */
/*   Updated: 2024/02/23 12:25:21 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Checks if the next bloc is wall, preventing the player from going further*/
static int	is_wall(double x, double y, t_data *data)
{
	x = floor(x);
	y = floor(y);
	if (data->map[(int)y][(int)x] == '1' ||
		data->map[(int)y][(int)x] == ' ' ||
		data->map[(int)y][(int)x] == '\0')
		return (1);
	return (0);
}

/*Checks if it is possible for the player to make a move within map boundaries
if his new position will be OOB or facing a wall
the player wouldn't be able to perfom any move*/
int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if ((!(new_x < 0.25 || new_x >= data->mapinfo.width - 1.25)
			&& !(new_y < 0.25 || new_y >= data->mapinfo.height - 0.25))
		&& !is_wall(new_x, new_y, data))
	{
		data->player.pos_x = new_x;
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

static int	rotate_left_right(t_data *data, double speed)
{
	t_player	*p;
	double		tmp_x;

	p = &data->player;
	tmp_x = p->dir_x;
	p->dir_x = p->dir_x * cos(speed) - p->dir_y * sin(speed);
	p->dir_y = tmp_x * sin(speed) + p->dir_y * cos(speed);
	tmp_x = p->plane_x;
	p->plane_x = p->plane_x * cos(speed) - p->plane_y * sin(speed);
	p->plane_y = tmp_x * sin(speed) + p->plane_y * cos(speed);
	return (1);
}

int	rotate(t_data *data, double rot_direction)
{
	int		moved;
	double	speed;

	moved = 0;
	speed = ROTATESPEED * rot_direction;
	moved += rotate_left_right(data, speed);
	return (moved);
}
