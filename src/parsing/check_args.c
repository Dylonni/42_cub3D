/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:52:05 by mba               #+#    #+#             */
/*   Updated: 2024/02/23 12:28:43 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

/*Checks if the the argument is a directory*/

static bool	is_dir(char *arg)
{
	int		fd;
	bool	ret;

	ret = false;
	fd = open(arg, __O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		ret = true;
	}
	return (ret);
}

/*Checks if the given argument is .xpm for the images*/

int	check_extension_xpm(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if (is_dir(arg))
		return (ft_putstr("Error: is a diectory"), 1);
	if ((arg[len - 3] != 'x') || (arg[len - 2] != 'p')
		|| (arg[len - 1] != 'm') || (arg[len - 4] != '.'))
		return (1);
	return (0);
}

/*Checks if the given argument is .cub for the map descriptor*/

static	bool	check_extension_cub(char *arg)
{
	int	len;

	len = ft_strlen(arg);
	if ((arg[len - 3] != 'c') || (arg[len - 2] != 'u')
		|| (arg[len - 1] != 'b') || (arg[len - 4] != '.'))
		return (false);
	return (true);
}

/*Does all the checkings above*/

int	check_file(char *arg)
{
	int	fd;

	if (is_dir(arg))
		return (ft_putstr("Error: is a diectory"), 1);
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		return (ft_putstr("Error: Can't open file"), 1);
	close(fd);
	if (!check_extension_cub(arg))
		return (ft_putstr("Error: extension .cub"), 1);
	return (0);
}
