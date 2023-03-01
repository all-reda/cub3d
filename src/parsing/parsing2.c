/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:33 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:04:36 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	map_skeleton(int fd, t_data *data)
{
	int		elem_count;
	char	*str;

	elem_count = 0;
	str = gnl_no_nl(fd);
	while (str && elem_count < 6)
	{
		if (!ft_is_identifier(str, data) && ft_is_blankline(str))
			elem_count++;
		else if (ft_is_blankline(str))
		{
			if (str)
				free(str);
			break ;
		}
		if (str)
			free(str);
		if (elem_count < 6)
			str = gnl_no_nl(fd);
	}
	if (elem_count != 6)
		return (1);
	return (0);
}

int	map_validation(int fd, t_data *data, char *str)
{
	t_char_lst	*temp_map;

	temp_map = 0;
	str = gnl_no_nl(fd);
	if (!str)
		return (ft_error_msg("Empty Map\n", 1));
	while (str && !ft_is_blankline(str))
		while_gnl(&str, fd);
	if (!str)
		return (ft_error_msg("Empty Map\n", 1));
	while (str && ft_is_blankline(str))
	{
		data->map->map_y++;
		if (new_lst_char(&temp_map, ft_strdup(str)))
			return (ft_error_msg("Malloc Error\n", 1));
		if ((int)ft_strlen(str) > data->map->map_x)
			data->map->map_x = (int)ft_strlen(str);
		while_gnl(&str, fd);
	}
	if (str)
		free(str);
	if (lst_to_tab_char(temp_map, data->map))
		return (ft_error_msg("Malloc Error\n", 1));
	free_lst(temp_map);
	return (0);
}

int	parse_map(char *str, t_data *data)
{
	int		fd;
	char	*map;

	map = ft_strtrim(str, " ");
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg("Open Map Fail\n", 1));
	if (map_skeleton(fd, data))
		return (ft_error_msg("Invalid Instruction\n", 1));
	if (map_validation(fd, data, 0))
		return (1);
	if (check_map(data))
		return (ft_error_msg("Invalid Map\n", 1));
	free(map);
	return (0);
}
