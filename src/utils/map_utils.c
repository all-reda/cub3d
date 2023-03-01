/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:12:18 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:12:23 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cellpos	get_player_pos(char **map)
{
	int			count;
	t_cellpos	rvalue;
	int			i;
	int			j;

	count = 0;
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				count++;
				rvalue.x = j + 0.5;
				rvalue.y = i + 0.5;
			}
			j++;
		}
	}
	if (!count || count > 1)
		rvalue.x = -1;
	return (rvalue);
}

double	get_player_rad(char dir)
{
	if (dir == 'N')
		return (3 * M_PI_2);
	if (dir == 'S')
		return (M_PI_2);
	if (dir == 'W')
		return (M_PI);
	else
		return (0);
}
