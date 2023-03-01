/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:51:48 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:51:50 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*rvalue;

	if (!dst || !src)
		return (dst);
	rvalue = dst;
	while (n--)
		*(char *)dst++ = *(char *)src++;
	return (rvalue);
}
