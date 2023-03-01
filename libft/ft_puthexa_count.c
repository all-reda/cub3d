/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:57:11 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:57:13 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthexa_count(unsigned int nb, int maj)
{
	char	*hextab;
	size_t	rvalue;

	rvalue = 0;
	if (maj == 1)
		hextab = "0123456789ABCDEF";
	else
		hextab = "0123456789abcdef";
	if (nb <= 15)
	{
		write(1, &hextab[nb], 1);
		return (rvalue + 1);
	}
	if (nb > 15)
	{
		rvalue += ft_puthexa_count(nb / 16, maj);
	}
	write(1, &hextab[nb % 16], 1);
	return (rvalue + 1);
}
