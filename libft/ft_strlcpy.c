/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:49:01 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:49:05 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	rvalue;

	if (!dst || !src)
		return (0);
	rvalue = ft_strlen(src);
	if (!dstsize)
		return (rvalue);
	while (--dstsize && *src)
		*dst++ = *src++;
	*dst = 0;
	return (rvalue);
}
