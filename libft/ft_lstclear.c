/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:43:46 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:43:58 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*mylist;

	mylist = *lst;
	if (del == 0 || lst == 0 || *lst == 0)
		return ;
	while (mylist->next != 0)
	{
		temp = mylist->next;
		del(mylist->content);
		free(mylist);
		mylist = temp;
	}
	del(mylist->content);
	free(mylist);
	*lst = 0;
}
