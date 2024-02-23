/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 10:48:27 by mba               #+#    #+#             */
/*   Updated: 2024/02/12 23:07:57 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Self explanatory*/
static int	count_map_lines(t_data *data, char **file, int i)
{
	int	index_value;
	int	j;

	index_value = i;
	while (file[i])
	{
		j = 0;
		while (file[i][j] == ' ' || file[i][j] == '\t' || file[i][j] == '\r'
				|| file[i][j] == '\v' || file[i][j] == '\f')
			j++;
		if (file[i][j] != '1')
			break ;
		i++;
	}
	data->mapinfo.index_end_map = i;
	return (i - index_value);
}

/*Stores the map into another pointer, so it can be used without
the descriptions*/
static int	fill_map_tab(t_mapinfo *mapinfo, char **map_tab, int index)
{
	int	i;
	int	j;

	mapinfo->width = find_biggest_len(mapinfo, index);
	i = 0;
	while (i < mapinfo->height)
	{
		j = 0;
		map_tab[i] = malloc(sizeof(char) * (mapinfo->width + 1));
		if (!map_tab[i])
			return (ft_putstr("error: malloc"), 1);
		while (mapinfo->file[index][j] && mapinfo->file[index][j] != '\n')
		{
			map_tab[i][j] = mapinfo->file[index][j];
			j++;
		}
		while (j < mapinfo->width)
			map_tab[i][j++] = '\0';
		i++;
		index++;
	}
	map_tab[i] = NULL;
	return (0);
}

/*Get the map from the file into the map pointer*/
static int	get_map_info(t_data *data, char **file, int i)
{
	data->mapinfo.height = count_map_lines(data, file, i);
	data->map = malloc(sizeof(char *) * (data->mapinfo.height + 1));
	if (!data->map)
		return (ft_putstr("error: malloc"), 1);
	if (fill_map_tab(&data->mapinfo, data->map, i) == 1)
		return (1);
	return (0);
}

/*Changes empty spaces in the map to 1's*/
static void	change_space_to_wall(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j] == ' ' || data->map[i][j] == '\t'
				|| data->map[i][j] == '\r' || data->map[i][j] == '\v'
				|| data->map[i][j] == '\f')
			j++;
		while (data->map[i][++j])
		{
			if (data->map[i][j] == ' ' &&
				j != data->map[i][ft_strlen(data->map[i]) - 1])
				data->map[i][j] = '1';
		}
		i++;
	}
}

/*Main function that will do all of the above*/
int	create_map(t_data *data, char **file, int i)
{
	if (get_map_info(data, file, i) == 1)
		return (1);
	change_space_to_wall(data);
	return (0);
}
