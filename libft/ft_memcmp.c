/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:47:48 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:47:56 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*d_s1;
	char	*d_s2;

	d_s1 = ((char *)s1);
	d_s2 = ((char *)s2);
	if (n == 0)
		return (0);
	while (*d_s1 == *d_s2 && --n != 0 && d_s1 && d_s2)
	{
		d_s1++;
		d_s2++;
	}
	return (((unsigned char)*d_s1) - ((unsigned char)*d_s2));
}
