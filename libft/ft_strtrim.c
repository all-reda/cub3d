/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:15:24 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:15:27 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*rvalue;
	size_t	i;

	while (ft_strchr(set, *s1) && *s1)
		s1++;
	i = ft_strlen(s1);
	while (ft_strchr(set, s1[i]) && *s1)
		i--;
	rvalue = malloc(i + 2);
	if (rvalue == 0)
		return (0);
	ft_strlcpy(rvalue, s1, i + 2);
	return (rvalue);
}
