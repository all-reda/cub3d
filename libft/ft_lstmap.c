/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:09:20 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:09:26 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*rvalue;
	t_list	*liststart;

	rvalue = ft_lstnew(f(lst->content));
	if (rvalue->content == 0 || rvalue == 0)
	{
		ft_lstclear(&liststart, del);
		return (0);
	}
	liststart = rvalue;
	while (lst->next != 0)
	{
		lst = lst->next;
		rvalue->next = ft_lstnew(f(lst->content));
		if (rvalue->content == 0 || rvalue == 0)
		{
			ft_lstclear(&liststart, del);
			return (0);
		}
		rvalue = rvalue->next;
	}
	return (liststart);
}
