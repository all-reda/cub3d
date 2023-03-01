/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:35:51 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:36:05 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *nw)
{
	t_list	*last;

	if (lst == 0 || nw == 0)
		return ;
	if (*lst == 0)
		*lst = nw;
	else
	{
	last = ft_lstlast(*lst);
	last->next = nw;
	}
}
