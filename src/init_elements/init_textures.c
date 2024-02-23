/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dylan <dylan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 12:06:24 by mba               #+#    #+#             */
/*   Updated: 2024/02/19 16:00:23 by dylan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Initializing the texture, storing adresses and data of xpm file into a proper
image buffer*/
void	init_texture_img(t_data *data, t_img *image, char *path)
{
	init_img_clean(image);
	image->img = mlx_xpm_file_to_image(data->mlx, path,
			&data->texinfo.size, &data->texinfo.size);
	if (image->img == NULL)
	{
		ft_putstr("Error: mlx img");
		exit_clean(data);
	}
	image->addr = (int *)mlx_get_data_addr(image->img,
			&image->pixel_bits, &image->size_line, &image->endian);
	return ;
}

/*Actual conversion of the xpm into an usable image*/
static int	*xpm_to_img(t_data *data, char *path)
{
	t_img	tmp;
	int		*buffer;
	int		x;
	int		y;

	init_texture_img(data, &tmp, path);
	buffer = ft_calloc(1, sizeof * buffer
			* data->texinfo.size * data->texinfo.size);
	if (!buffer)
		exit_clean(data);
	y = 0;
	while (y < data->texinfo.size)
	{
		x = 0;
		while (x < data->texinfo.size)
		{
			buffer[y * data->texinfo.size + x]
				= tmp.addr[y * data->texinfo.size + x];
			++x;
		}
		y++;
	}
	mlx_destroy_image(data->mlx, tmp.img);
	return (buffer);
}

/* Put all the xpm files to proper renderable images
images are stored into texture[] , corresponding to the different
directions (0 is north , 1 is south ...)*/
void	init_textures(t_data *data)
{
	data->textures = ft_calloc(5, sizeof * data->textures);
	if (!data->textures)
	{
		ft_putstr("Error: malloc");
		exit_clean(data);
	}
	data->textures[0] = xpm_to_img(data, data->texinfo.north);
	data->textures[1] = xpm_to_img(data, data->texinfo.south);
	data->textures[2] = xpm_to_img(data, data->texinfo.east);
	data->textures[3] = xpm_to_img(data, data->texinfo.west);
}
