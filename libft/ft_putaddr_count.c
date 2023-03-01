/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr_count.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:44:59 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:45:03 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putaddr_count(unsigned long nb, int ox)
{
	char	*hextab;
	size_t	rvalue;

	rvalue = 0;
	if (ox == 1)
		rvalue += write(1, "0x", 2);
	hextab = "0123456789abcdef";
	if (nb <= 15)
	{
		write(1, &hextab[nb], 1);
		return (rvalue + 1);
	}
	if (nb > 15)
	{
		rvalue += ft_putaddr_count(nb / 16, 0);
	}
	write(1, &hextab[nb % 16], 1);
	return (rvalue + 1);
}
