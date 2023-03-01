/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:14:08 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:14:13 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_is_blankline(const char *s1)
{
	while (ft_strchr(" \t\n\v\f\r", *s1) && *s1)
		s1++;
	if (*s1)
		return (1);
	return (0);
}

char	*gnl_no_nl(int fd)
{
	char	*str;
	char	*nonl;
	int		i;

	nonl = 0;
	i = 0;
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	if (ft_strchr(str, '\n'))
	{
		nonl = (char *)malloc(sizeof(char) * ft_strlen(str));
		if (!nonl)
			return (NULL);
		i = ft_strlcpy(nonl, str, ft_strlen(str));
		if (!i)
			return (NULL);
		free(str);
	}
	else
		nonl = str;
	return (nonl);
}

int	ft_load_txtr(t_txtr txtr, char *str, t_data *data)
{
	int	fd;

	if (data->map->txtr_tab[txtr])
		return (ft_error_msg("Invalid identifier doublon\n", 1));
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("Texture doesn't exist\n", 1));
	data->map->txtr_tab[txtr] = ft_strdup(str);
	return (0);
}

int	ft_check_color(t_txtr txtr, char *str, t_data *data)
{
	char	**color;
	int		i;
	int		n;

	i = 0;
	color = ft_split(str, ',');
	while (color[i])
	{
		n = ft_isnumber(color[i]);
		if (n < 0 || n > 255)
			return (ft_error_free("Invalid number\n", &free_tab, color));
		data->map->color_tab[txtr - 4][i] = (short)n;
		i++;
	}
	if (i != 3)
		return (ft_error_free("Invalid color value\n", &free_tab, color));
	free_tab(color);
	return (0);
}

int	ft_is_identifier(char *str, t_data *data)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (ft_load_txtr(NO, str + 3, data));
	else if (!ft_strncmp(str, "SO ", 3))
		return (ft_load_txtr(SO, str + 3, data));
	else if (!ft_strncmp(str, "WE ", 3))
		return (ft_load_txtr(WE, str + 3, data));
	else if (!ft_strncmp(str, "EA ", 3))
		return (ft_load_txtr(EA, str + 3, data));
	else if (!ft_strncmp(str, "F ", 2))
		return (ft_check_color(F, str + 2, data));
	else if (!ft_strncmp(str, "C ", 2))
		return (ft_check_color(C, str + 2, data));
	return (1);
}
