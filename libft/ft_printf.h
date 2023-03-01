/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:18:24 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 14:18:29 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

size_t	ft_putstr_count(char *s);
size_t	ft_putnbr_count(int n);
size_t	ft_putunbr_count(unsigned int n);
size_t	ft_puthexa_count(unsigned int nb, int maj);
size_t	ft_putaddr_count(unsigned long nb, int ox);
int		ft_printf(const char *format, ...);

#endif
