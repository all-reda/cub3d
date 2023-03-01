/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:04:14 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:04:19 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	cub_suffix(char *str)
{
	char	*suffix;
	int		i;

	i = 0;
	suffix = ft_strtrim(str, " ");
	if (ft_strlen(suffix) < 5)
		return (ft_error_free("Map name too small\n", &free_str, suffix));
	while (suffix[i])
		if (ft_isspace(suffix[i++]))
			return (ft_error_free("Space in map\n", &free_str, suffix));
	i -= 4;
	if (ft_strncmp(suffix + i, ".cub", 5))
		return (ft_error_free("Invalid Map Suffix\n", &free_str, suffix));
	free(suffix);
	return (0);
}

int	map_init(t_map **map)
{
	int	i;

	*map = (t_map *)malloc(sizeof(t_map));
	if (!*map)
		return (1);
	i = 0;
	while (i < 3)
		(*map)->color_tab[0][i++] = -1;
	i = 0;
	while (i < 3)
		(*map)->color_tab[1][i++] = -1;
	(*map)->color_tab[0][3] = 255;
	(*map)->color_tab[1][3] = 255;
	i = 0;
	while (i < 5)
		(*map)->txtr_tab[i++] = 0;
	(*map)->map_tab = 0;
	(*map)->map_x = 0;
	(*map)->map_y = 0;
	return (0);
}

int	parse_arg(t_data *data, int argc, char **argv)
{
	data->texture = 0;
	data->map = 0;
	if (argc != 2)
		return (ft_error_msg("Invalid Argument Number\n", 1));
	else if (cub_suffix(argv[1]))
		return (1);
	if (map_init(&data->map))
		return (1);
	if (parse_map(argv[1], data))
		return (1);
	return (0);
}
