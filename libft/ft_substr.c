/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:34:34 by mba               #+#    #+#             */
/*   Updated: 2022/11/23 16:09:43 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	i;
	char	*str;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	if (s_len <= start || !(*s) || len == 0)
		return (ft_calloc(1, 1));
	if (s_len - start < len)
		str = (char *)malloc(s_len - start + 1);
	else
		str = (char *)malloc(len + 1);
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}
