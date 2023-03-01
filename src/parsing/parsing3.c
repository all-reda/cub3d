/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:05:08 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:05:36 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_first_line(char **map_tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->map_x)
	{
		if (j == map->map_y)
			return (1);
		if (j == map->map_y - 3 && map_tab[j][i] != 1)
			return (1);
		if (map_tab[j][i] == ' ')
		{
			j++;
			continue ;
		}
		else if (map_tab[j][i] == '1')
			j = 0;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_last_line(char **map_tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = map->map_y - 1;
	while (i < map->map_x)
	{
		if (j == -1)
			return (1);
		if (j == 2 && map_tab[j][i] != 1)
			return (1);
		if (map_tab[j][i] == ' ')
		{
			j--;
			continue ;
		}
		else if (map_tab[j][i] == '1')
			j = map->map_y - 1;
		else
			return (1);
		i++;
	}
	return (0);
}

int	check_first_collumn(char **map_tab, t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < map->map_y)
	{
		if (i == map->map_x)
			return (1);
		if (i == map->map_x - 3 && map_tab[j][i] != 1)
			return (1);
		if (map_tab[j][i] == ' ')
		{
			i++;
			continue ;
		}
		else if (map_tab[j][i] == '1')
			i = 0;
		else
			return (1);
		j++;
	}
	return (0);
}

int	check_last_collumn(char **map_tab, t_map *map)
{
	int	i;
	int	j;

	i = map->map_x - 1;
	j = 0;
	while (j < map->map_y)
	{
		if (i == -1)
			return (1);
		if (i == 2 && map_tab[j][i] != 1)
			return (1);
		if (map_tab[j][i] == ' ')
		{
			i--;
			continue ;
		}
		else if (map_tab[j][i] == '1')
			i = map->map_x - 1;
		else
			return (1);
		j++;
	}
	return (0);
}

int	check_map(t_data *data)
{
	if (data->map->map_x < 2 || data->map->map_y < 2)
		return (ft_error_msg("Map Too Small\n", 1));
	if (check_first_line(data->map->map_tab, data->map))
		return (ft_error_msg("Map Isn't Closed\n", 1));
	if (check_first_collumn(data->map->map_tab, data->map))
		return (ft_error_msg("Map Isn't Closed\n", 1));
	if (check_last_line(data->map->map_tab, data->map))
		return (ft_error_msg("Map Isn't Closed\n", 1));
	if (check_last_collumn(data->map->map_tab, data->map))
		return (ft_error_msg("Map Isn't Closed\n", 1));
	if (check_map_inside(data->map))
		return (ft_error_msg("Map Isn't Closed\n", 1));
	return (0);
}
