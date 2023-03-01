/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:37:17 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:37:22 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*rvalue;

	rvalue = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (rvalue == 0)
		return (0);
	ft_strlcpy(rvalue, s1, ft_strlen(s1) + 1);
	ft_strlcpy(rvalue + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (rvalue);
}
