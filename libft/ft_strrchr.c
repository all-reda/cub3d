/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:53:17 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:53:19 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	d;

	d = (unsigned char)c;
	i = ft_strlen(s);
	i++;
	while (i-- != 0)
		if (s[i] == d)
			return (((char *)&s[i]));
	return (0);
}
