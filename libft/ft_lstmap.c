/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 16:58:26 by mba               #+#    #+#             */
/*   Updated: 2022/12/01 13:30:49 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_case;
	t_list	*list;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		new_case = ft_lstnew((*f)(lst->content));
		if (new_lst == 0)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(list, new_case);
		lst = lst->next;
	}
	return (list);
}
