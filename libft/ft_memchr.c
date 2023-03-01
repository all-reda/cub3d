/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:44:25 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:44:30 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*rvalue;
	char	d;

	d = (unsigned char)c;
	if (!s)
		return (0);
	rvalue = ((char *)s);
	while (n--)
	{
		if (*rvalue == d)
			return ((void *)rvalue);
		rvalue++;
	}
	return (0);
}
