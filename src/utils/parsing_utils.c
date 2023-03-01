/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:13:06 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:13:12 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_is_separator(char c, char *sep)
{
	while (sep && *sep)
		if (c == *(sep++))
			return (1);
	return (0);
}

void	while_gnl(char **str, int fd)
{
	if (*str)
		free(*str);
	*str = gnl_no_nl(fd);
}

int	line_fill(t_char_lst *lst, t_map *map, int j)
{
	int	i;

	i = 0;
	while (i < map->map_x)
	{
		if (i < (int)ft_strlen(lst->line))
		{
			if (ft_is_separator(lst->line[i], "01WESN "))
				map->map_tab[j][i] = lst->line[i];
			else
				return (ft_error_msg("Invalid Map character\n", 1));
		}
		else
			map->map_tab[j][i] = ' ';
		i++;
	}
	map->map_tab[j][i] = '\0';
	return (0);
}

int	lst_to_tab_char(t_char_lst *lst, t_map *map)
{
	int	j;

	map->map_tab = (char **)malloc(sizeof(char *) * (map->map_y + 1));
	if (!map->map_tab)
		return (1);
	j = 0;
	while (j < map->map_y)
	{
		map->map_tab[j] = (char *)malloc(sizeof(char) * (map->map_x + 1));
		if (!map->map_tab[j])
			return (1);
		if (line_fill(lst, map, j))
			return (1);
		if (lst->next)
			lst = lst->next;
		j++;
	}
	map->map_tab[j] = 0;
	return (0);
}

int	check_map_inside(t_map *map)
{
	int		i;
	int		j;
	char	**m;

	j = 1;
	m = map->map_tab;
	while (j < map->map_y - 1)
	{
		i = 1;
		while (i < map->map_x - 1)
		{
			if (m[j][i] == '0' && (m[j][i + 1] == ' ' || m[j][i - 1] == ' '
					|| m[j + 1][i] == ' ' || m[j - 1][i] == ' '
					|| m[j + 1][i + 1] == ' ' || m[j + 1][i - 1] == ' '
					|| m[j - 1][i + 1] == ' ' || m[j - 1][i - 1] == ' '))
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}
