/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:48:19 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:48:24 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*rvalue;

	if (s == 0)
		return (0);
	if (len > ft_strlen(s))
		rvalue = malloc(ft_strlen(s) + 1);
	else
		rvalue = malloc(len + 1);
	if (rvalue == 0)
		return (0);
	if (ft_strlen(s) < start)
	{
		rvalue[0] = 0;
		return (rvalue);
	}
	s = s + start;
	ft_strlcpy(rvalue, s, len + 1);
	return (rvalue);
}
