/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:15:58 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 13:16:07 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	rvalue;
	int	minus;

	rvalue = 0;
	minus = 0;
	if (str == 0)
		return (0);
	while (*str == ' ' || *str == '\n' || *str == '\t'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
	{
		minus = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		rvalue = (rvalue * 10) + (*str - 48);
		str++;
	}
	if (minus == 1)
		rvalue = rvalue * -1;
	return (rvalue);
}
