/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:05:06 by mba               #+#    #+#             */
/*   Updated: 2024/02/19 15:58:27 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Checks wheter there is N , S , W or E in the map descriptor*/
static int	check_map_elements(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = 0;
	data->player.dir = '0';
	while (map_tab[i] != NULL)
	{
		j = 0;
		while (map_tab[i][j])
		{
			while (map_tab[i][j] == ' ' || map_tab[i][j] == '\t'
					|| map_tab[i][j] == '\r' || map_tab[i][j] == '\v'
					|| map_tab[i][j] == '\f')
				j++;
			if (!(ft_strchr("10NSEW", map_tab[i][j])))
				return (ft_putstr("error: invalid caractere"), 1);
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir != '0')
				return (ft_putstr("error: player Number"), 1);
			if (ft_strchr("NSEW", map_tab[i][j]) && data->player.dir == '0')
				data->player.dir = map_tab[i][j];
			j++;
		}
		i++;
	}
	return (0);
}

/*Checks if the player's position is valid*/
static int	check_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	i = (int)data->player.pos_y;
	j = (int)data->player.pos_x;
	if (ft_strlen(map_tab[i + 1]) < j
		|| ft_strlen(map_tab[i - 1]) < j
		|| is_a_white_space(map_tab[i][j - 1]) == 0
		|| is_a_white_space(map_tab[i][j + 1]) == 0
		|| is_a_white_space(map_tab[i + 1][j]) == 0
		|| is_a_white_space(map_tab[i - 1][j]) == 0)
		return (1);
	return (0);
}

/*Checks and fills the informations for the player's position*/
static int	check_player_position(t_data *data, char **map_tab)
{
	int	i;
	int	j;

	if (data->player.dir == '0')
		return (ft_putstr("error: player direction"));
	i = 0;
	while (map_tab[i])
	{
		j = 0;
		while (map_tab[i][j])
		{
			if (ft_strchr("NSEW", map_tab[i][j]))
			{
				data->player.pos_x = (double)j + 0.5;
				data->player.pos_y = (double)i + 0.5;
				map_tab[i][j] = '0';
			}	
			j++;
		}
		i++;
	}
	if (check_position(data, map_tab) == 1)
		return (ft_putstr("error: player position"));
	return (0);
}

/*Fills up infos of where the map ends*/
static int	check_map_end(t_mapinfo *map)
{
	int	i;
	int	j;

	i = map->index_end_map;
	while (map->file[i])
	{
		j = 0;
		while (map->file[i][j])
		{
			if (map->file[i][j] != ' ' && map->file[i][j] != '\t'
				&& map->file[i][j] != '\r' && map->file[i][j] != '\n'
				&& map->file[i][j] != '\v' && map->file[i][j] != '\f')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*All of those functions are there to check if the map is playable*/
int	check_map_validity(t_data *data, char **map_tab)
{
	if (!data->map)
		return (ft_putstr("error: map"), 1);
	if (check_map_sides(&data->mapinfo, map_tab) == 1)
		return (ft_putstr("error: wall"), 1);
	if (data->mapinfo.height < 3)
		return (ft_putstr("error: map"), 1);
	if (check_map_elements(data, map_tab) == 1)
		return (1);
	if (check_player_position(data, map_tab) == 1)
		return (1);
	if (check_map_end(&data->mapinfo) == 1)
		return (ft_putstr("Error: map is not at the end in file"), 1);
	return (0);
}
