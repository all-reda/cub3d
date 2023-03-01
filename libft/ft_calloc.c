/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:46:46 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:46:50 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*rvalue;

	rvalue = malloc(nmemb * size);
	if (rvalue == 0)
		return (0);
	ft_bzero(rvalue, nmemb * size);
	return (rvalue);
}
