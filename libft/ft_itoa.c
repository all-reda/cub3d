/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:08:40 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:08:47 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*alloc(int nbr, int *i)
{
	char	*str;

	*i = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		*i = *i + 1;
	}
	if (nbr == 0)
		*i = 1;
	while (nbr)
	{
		nbr /= 10;
		*i = *i + 1;
	}
	str = (char *)malloc(*i + 1);
	if (!str)
		return (0);
	str[*i] = '\0';
	return (str);
}

static	void	tostring(int n, char *nbr, int i)
{
	if (n == -2147483648)
	{
		n = -214748364;
		nbr[--i] = '8';
	}
	if (n < 0)
	{
		n *= -1;
		nbr[0] = '-';
	}
	if (n == 0)
		nbr[0] = '0';
	while (n > 9)
	{
		nbr[--i] = (n % 10) + 48;
		n /= 10;
	}
	nbr[--i] = n + 48;
}

char	*ft_itoa(int n)
{
	char	*nbr;
	int		i;

	nbr = alloc(n, &i);
	if (!nbr)
		return (NULL);
	tostring(n, nbr, i);
	return (nbr);
}
