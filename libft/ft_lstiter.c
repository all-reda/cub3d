/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:51:22 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:51:24 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (f == 0 || lst == 0)
		return ;
	while (lst->next != 0)
	{
		temp = lst->next;
		f(lst->content);
		lst = temp;
	}
	f(lst->content);
}
