/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 09:53:00 by mba               #+#    #+#             */
/*   Updated: 2024/02/23 12:20:12 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Checks if the map is well closed at the top and bottom*/
static int	check_borders(char **map_tab, int i, int j)
{
	if (!map_tab || !map_tab[i] || !map_tab[i][j])
		return (1);
	while (map_tab[i][j] == ' ')
		j++;
	while (map_tab[i][j])
	{
		if (map_tab[i][j] == '\t' || map_tab[i][j] == '\r'
			|| map_tab[i][j] == '\v' || map_tab[i][j] == '\f')
			return (1);
		if (map_tab[i][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

/*Checks if the map is well closed both on sides and at the top/bottom*/
int	check_map_sides(t_mapinfo *map, char **map_tab)
{
	int	i;
	int	j;

	if (check_borders(map_tab, 0, 0) == 1)
		return (1);
	i = 1;
	while (i < map->height - 1)
	{
		j = ft_strlen(map_tab[i]) - 1;
		if (map_tab[i][j] != '1')
			return (1);
		i++;
	}
	if (check_borders(map_tab, i, 0) == 1)
		return (1);
	return (0);
}

/*This function will replace voids on the sides
by 1's to ensure map is well closed*/
void	close_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mapinfo.height)
	{
		j = 0;
		if (ft_strlen(map[i]) < data->mapinfo.width)
		{
			while (j < ft_strlen(map[i]))
			{
				if (map[i][j] == ' ')
					map[i][j] = '1';
				else
					map[i][j] = map[i][j];
				j++;
			}
			while (j < data->mapinfo.width)
			{
				map[i][j] = '1';
				j++;
			}
		}
		i++;
	}
}
