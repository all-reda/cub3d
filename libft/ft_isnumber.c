/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:41:30 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 15:42:48 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnumber(char *str)
{
	int	rvalue;

	rvalue = 0;
	while (*str)
	{
		if (*str >= 48 && *str <= 57)
		{
			rvalue = rvalue * 10;
			rvalue += (*str - 48);
		}
		else if (*str == '\n')
			break ;
		else if (*str != ' ')
			return (999);
		str++;
	}
	if (rvalue < 0 || rvalue > 255)
		return (999);
	return (rvalue);
}
