/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:15:38 by mba               #+#    #+#             */
/*   Updated: 2024/02/23 12:23:34 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/*Parsing elements before */
static int	parse_args(t_data *data, char **av)
{
	if (check_file(av[1]))
		exit_clean(data);
	parse_data(av[1], data);
	if (read_data(data, data->mapinfo.file))
		return (free_data(data));
	if (check_map_validity(data, data->map))
		return (free_data(data));
	if (check_textures_validity(&data->texinfo))
		return (free_data(data));
	close_map(data, data->map);
	init_player_direction(data);
	return (0);
}

static	void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		ft_putstr("Error: mlx");
		exit_clean(data);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!data->win)
	{
		ft_putstr("Error: mlx window");
		exit_clean(data);
	}
	init_textures(data);
	render_images(data);
	input_handler(data);
	mlx_loop_hook(data->mlx, render_images, data);
	mlx_loop(data->mlx);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_putstr("error: arguments"));
	init_data(&data);
	if (parse_args(&data, av) != 0)
		return (1);
	init_game(&data);
	return (0);
}
