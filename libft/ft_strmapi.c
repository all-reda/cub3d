/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:58:03 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:58:07 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*rvalue;

	if (s == 0)
		return (0);
	rvalue = malloc(ft_strlen(s) + 1);
	if (rvalue == 0)
		return (0);
	i = 0;
	while (s[i])
	{
		rvalue[i] = f(i, s[i]);
		i++;
	}
	rvalue[i] = 0;
	return (rvalue);
}
