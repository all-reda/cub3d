/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:04 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:03:07 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	set_color(unsigned char *img, char c)
{
	if (c == ' ')
	{
		img[0] = 0;
		img[1] = 0;
		img[2] = 0;
		img[3] = 0;
	}
	else if (c == '1')
	{
		img[0] = 184;
		img[1] = 12;
		img[2] = 0;
		img[3] = 80;
	}
	else
	{
		img[0] = 143;
		img[1] = 140;
		img[2] = 119;
		img[3] = 80;
	}
}

void	*fill_cell(void *img, char c)
{
	int	i;

	i = 0;
	while (i < CELLSIZE)
	{
		set_color((unsigned char *)img, c);
		img = img + 4;
		i++;
	}
	return (img);
}

void	*fill_line(void *img, char *map_line)
{
	int	i;

	i = 0;
	while (map_line[i])
	{
		img = fill_cell(img, map_line[i]);
		i++;
	}
	return (img);
}

void	fill_minimap(t_data *data)
{
	int				i;
	int				j;
	unsigned char	*px;

	px = data->minimap_img->pixels;
	i = 0;
	while (data->map->map_tab[i])
	{
		j = 0;
		while (j < CELLSIZE)
		{
			px = fill_line(px, data->map->map_tab[i]);
			j++;
		}
		i++;
	}
	put_player_minimap(data->minimap_img, data->player);
}

mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map)
{
	mlx_image_t	*minimap_img;

	minimap_img = mlx_new_image(mlx, map->map_x * CELLSIZE, map->map_y
			* CELLSIZE);
	if (!minimap_img)
		return (0);
	return (minimap_img);
}
