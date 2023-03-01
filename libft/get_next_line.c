/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:50:14 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:50:17 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_gnljoin(char *s1, char *s2)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + 2);
	if (!str)
		return (NULL);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	ft_strlcpy(str + ft_strlen(s1), s2, 2);
	if (*s1)
		free(s1);
	return (str);
}

char	*get_next_line(int fd)
{
	char	buffer[2];
	int		rdbl;
	char	*str;

	rdbl = 1;
	str = 0;
	buffer[0] = 0;
	if (fd >= 0)
	{
		buffer[1] = '\0';
		str = "";
	}
	else
		return (NULL);
	while (fd >= 0 && *buffer != '\n' && rdbl > 0)
	{
		rdbl = read(fd, buffer, 1);
		if (rdbl > 0)
			str = ft_gnljoin(str, buffer);
		else if (!*str)
			str = NULL;
	}
	return (str);
}
