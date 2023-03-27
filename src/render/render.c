/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <fl-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:07:08 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/27 15:49:42 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	txtr_pixel(t_data *data, int txcol, int txlin)
{
	if (data->player->hit == 0)
		return (data->texture->no[txcol][txlin]);
	else if (data->player->hit == 1)
		return (data->texture->so[txcol][txlin]);
	else if (data->player->hit == 2)
		return (data->texture->ea[txcol][txlin]);
	else if (data->player->hit == 3)
		return (data->texture->we[txcol][txlin]);
	return (0);
}

void	render_wall(int wall_height, t_data *data, int column, int i)
{
	uint32_t	*map;
	int			gap;
	int			txcol;
	int			txlin;

	map = (uint32_t *)data->mlx_img->pixels + column;
	wall_height -= wall_height % 2;
	txcol = data->texture->txr * data->player->hitp;
	gap = (wall_height - HEIGHT) / 2;
	column = HEIGHT;
	if (wall_height <= HEIGHT && wall_height > 0)
	{
		while (i++ < (HEIGHT / 2) - (wall_height / 2))
			map += WIDTH;
		gap = 0;
		column = (HEIGHT / 2) + (wall_height / 2);
	}
	while (i++ < column)
	{
		txlin = gap * ((double)data->texture->txr / (wall_height - 1));
		*map = txtr_pixel(data, txcol, txlin);
		map += WIDTH;
		gap++;
	}
}

uint32_t	**tab_txtr_malloc(xpm_t **xpm, t_data *data)
{
	uint32_t	**tab;
	int			i;

	tab = (uint32_t **)malloc(sizeof(uint32_t *) * (*xpm)->texture.height);
	if (!tab)
	{
		mlx_delete_xpm42(*xpm);
		return (NULL);
	}
	i = 0;
	while (i < (int)(*xpm)->texture.height)
	{
		tab[i] = malloc(sizeof(uint32_t) * (int)(*xpm)->texture.width);
		if (!tab[i])
		{
			mlx_delete_xpm42(*xpm);
			return (NULL);
		}
		i++;
	}
	data->texture->txr = 0;
	if ((*xpm)->texture.height)
		data->texture->txr = (*xpm)->texture.height - 1;
	return (tab);
}

int	data_struct_convert(uint32_t ***dir, const char *path, t_data *data)
{
	int			i;
	int			j;
	xpm_t		*xpm;
	uint32_t	**tab;
	uint32_t	*pixelptr;

	xpm = mlx_load_xpm42(path);
	if (!xpm)
		return (1);
	tab = tab_txtr_malloc(&xpm, data);
	if (!tab)
		return (1);
	i = 0;
	pixelptr = (uint32_t *)xpm->texture.pixels;
	while (i < (int)xpm->texture.height)
	{
		j = -1;
		while (++j < (int)xpm->texture.width)
			tab[j][i] = pixelptr[(i * (int)xpm->texture.height) + j];
		i++;
	}
	mlx_delete_xpm42(xpm);
	*dir = tab;
	return (0);
}

void	cub3d(t_data *data)
{
	mlx_delete_image(data->mlx, data->mlx_img);
	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	put_full_img(data);
	mlx_image_to_window(data->mlx, data->mlx_img, 0, 0);
	mlx_delete_image(data->mlx, data->minimap_img);
	data->minimap_img = create_minimap(data->mlx, data->map);
	fill_minimap(data);
	mlx_image_to_window(data->mlx, data->minimap_img, 0, 0);
}
