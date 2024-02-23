/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:42:23 by mba               #+#    #+#             */
/*   Updated: 2022/11/23 13:55:14 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	if (!(nb == -2147483648))
	{
		if (nb >= 0 && nb <= 9)
		{
			ft_putchar_fd(nb + '0', fd);
		}
		else if (nb < 0)
		{
			ft_putchar_fd('-', fd);
			ft_putnbr_fd((nb * (-1)), fd);
		}
		else
		{
			ft_putnbr_fd((nb / 10), fd);
			ft_putnbr_fd((nb % 10), fd);
		}
	}
	else
	{
		write (fd, "-2147483648", 11);
	}
}
