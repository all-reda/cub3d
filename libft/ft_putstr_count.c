/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_count.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:19:11 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 14:19:20 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr_count(char *s)
{
	size_t	rvalue;

	rvalue = 0;
	if (s == 0)
		return (write(1, "(null)", 6));
	while (*s)
	{
		write(1, &*s, 1);
		s++;
		rvalue++;
	}
	return (rvalue);
}
