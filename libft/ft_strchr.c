/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:57:41 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:57:45 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	d;

	d = (unsigned char)c;
	while (*s)
	{
		if (*s == d)
			return ((char *)s);
		s++;
	}
	if (*s == 0 && d == 0)
		return (((char *)s));
	return (0);
}
