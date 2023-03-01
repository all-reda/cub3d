/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:45:47 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:45:51 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	rvalue;
	size_t	i;

	if (!dst || !src)
		return (0);
	rvalue = ft_strlen(dst) + ft_strlen(src);
	if (!dstsize)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (*dst)
	{
		dst++;
		i++;
	}
	while (--dstsize > i && *src)
	{
		*dst++ = *src++;
	}
	*(dst) = 0;
	return (rvalue);
}
