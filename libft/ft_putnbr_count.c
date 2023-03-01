/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:13:33 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:13:40 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr_count(int n)
{
	char	c;
	size_t	rvalue;

	rvalue = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n = n * -1;
		write(1, "-", 1);
		rvalue++;
	}
	if (n >= 10)
		rvalue += ft_putnbr_count(n / 10);
	c = (n % 10) + 48;
	write(1, &c, 1);
	return (rvalue + 1);
}
