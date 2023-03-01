/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:14:06 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:14:19 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*rvalue;
	int		i;

	if (!s)
		return (0);
	i = 0;
	rvalue = malloc(ft_strlen(s) + 1);
	if (rvalue == 0)
		return (0);
	while (s[i])
	{
		rvalue[i] = s[i];
		i++;
	}
	rvalue[i] = 0;
	return (rvalue);
}
