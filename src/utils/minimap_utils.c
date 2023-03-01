/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:12:37 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:12:43 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

unsigned char	*set_player_color(unsigned char *playerpos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		playerpos[0] = 80;
		playerpos[1] = 249;
		playerpos[2] = 86;
		playerpos[3] = 255;
		playerpos += 4;
		i++;
	}
	return (playerpos);
}

void	put_player_minimap(mlx_image_t	*minimap, t_player *player)
{
	int				p_size;
	int				first_px;
	unsigned char	*px;
	int				i;
	t_cellpos		pos;

	p_size = floor(CELLSIZE / 2.0);
	pos.x = floor(player->pos.x * 10) / 10;
	pos.y = floor(player->pos.y * 10) / 10;
	first_px = ((minimap->width * pos.y + pos.x) * CELLSIZE * 4);
	first_px -= (p_size / 2 * minimap->width * 4) + (p_size * 2);
	px = minimap->pixels + first_px;
	i = 0;
	while (i < p_size)
	{
		px = set_player_color(px, p_size);
		px += minimap->width * 4 - p_size * 4;
		i++;
	}
}
