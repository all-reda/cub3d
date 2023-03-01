/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:00:21 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:00:25 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_error_msg(char *str, int errno)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	return (errno);
}

int	ft_error_free(char *str, void (*func)(void *), void *var)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(str, 2);
	(*func)(var);
	return (1);
}
