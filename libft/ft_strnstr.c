/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:46:08 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:46:12 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int		i;
	char	*rvalue;

	rvalue = ((char *)haystack);
	if (*needle == 0)
		return ((char *)haystack);
	while (*rvalue && n)
	{
		if (*rvalue == *needle)
		{
			i = 0;
			while (rvalue[i] == needle[i] && (n - i) != 0)
			{
				i++;
				if (needle[i] == 0)
					return (rvalue);
			}
		}
		n--;
		rvalue++;
	}
	return (0);
}
