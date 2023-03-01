/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:39:05 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:39:27 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	print_args(char type, va_list args)
{
	size_t	rvalue;
	char	c;

	rvalue = 0;
	if (type == 'c')
	{
		c = va_arg(args, int);
		rvalue = write(1, &c, 1);
	}
	else if (type == 'd' || type == 'i')
		rvalue = ft_putnbr_count(va_arg(args, int));
	else if (type == 's')
		rvalue = ft_putstr_count(va_arg(args, char *));
	else if (type == '%')
		rvalue = write(1, "%", 1);
	else if (type == 'u')
		rvalue = ft_putunbr_count(va_arg(args, int));
	else if (type == 'p')
		rvalue = ft_putaddr_count(va_arg(args, unsigned long), 1);
	else if (type == 'x')
		rvalue = ft_puthexa_count(va_arg(args, unsigned int), 0);
	else if (type == 'X')
		rvalue = ft_puthexa_count(va_arg(args, unsigned int), 1);
	return (rvalue);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	rvalue;

	rvalue = 0;
	va_start(args, format);
	while (*format != 0)
	{
		if (*format == '%')
		{
			format++;
			rvalue += print_args(*format, args);
		}
		else
		{
			rvalue += write(1, &format[0], 1);
		}
		format++;
	}
	return (rvalue);
}
