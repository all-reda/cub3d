/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:52:22 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:52:27 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	countstr(const char *s, char c)
{
	size_t		size;
	const char	*temp;

	temp = s;
	size = 0;
	while (*temp)
	{
		if (*temp != c)
			size++;
		temp++;
	}
	if (size == 0)
		return (0);
	size = 1;
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1) != '\0')
			size++;
		s++;
	}
	return (size);
}

static size_t	countcurrent(const char *s, char c)
{
	size_t	size;

	size = 0;
	while (*s != c && *s++)
		size++;
	return (size);
}

static void	copycurrent(char *dst, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**rvalue;
	size_t	tab_size;
	size_t	i;

	tab_size = countstr(s, c);
	rvalue = malloc((tab_size + 1) * sizeof(char *));
	if (rvalue == 0)
		return (0);
	i = 0;
	while (i < tab_size)
	{
		while (*s == c)
			s++;
		rvalue[i] = malloc(countcurrent(s, c) + 1);
		if (rvalue[i] == 0)
		{
			ft_free_strtab(rvalue);
			return (0);
		}
		copycurrent(rvalue[i], s, c);
		s = s + countcurrent(s, c) + 1;
		i++;
	}
	rvalue[i] = 0;
	return (rvalue);
}
