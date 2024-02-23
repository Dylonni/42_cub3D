/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 08:37:30 by mba               #+#    #+#             */
/*   Updated: 2024/02/12 23:03:02 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Checks if the given value can be turned into an rgb value*/
static	int	check_valid_rgb(int *rgb)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (ft_putstr("Error: invalid rgb value"));
		i++;
	}
	return (0);
}

/*Converts the values into rgb values and return the final rgb value*/
static unsigned long	convert_rgb_to_hex(int *rgb_tab)
{
	unsigned long	result;
	int				r;
	int				g;
	int				b;

	r = rgb_tab[0];
	g = rgb_tab[1];
	b = rgb_tab[2];
	result = ((r & 255) << 16) + ((g & 255) << 8) + (b & 255);
	return (result);
}

/*Checks wheter there are valid informations in the map descriptor for textures
and colors*/
int	check_textures_validity(t_texinfo *textures)
{
	if (!textures->north || !textures->south || !textures->west
		|| !textures->east)
		return (ft_putstr("Error: Missing textures"));
	if (!textures->floor || !textures->ceiling)
		return (ft_putstr("Error: Missing colors"));
	if (check_extension_xpm(textures->north) == 1
		|| check_extension_xpm(textures->south) == 1
		|| check_extension_xpm(textures->west) == 1
		|| check_extension_xpm(textures->east) == 1
		|| check_valid_rgb(textures->floor) == 1
		|| check_valid_rgb(textures->ceiling) == 1)
		return (1);
	textures->hex_floor = convert_rgb_to_hex(textures->floor);
	textures->hex_ceiling = convert_rgb_to_hex(textures->ceiling);
	return (0);
}
