/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <fl-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:39 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/23 18:28:49 by fl-hote          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	put_full_img(t_data *data)
{
	double		start_rad;
	double		gap_rad;
	double		wall_size;
	int			width_sweep;
	uint32_t	*mapc;

	mapc = (uint32_t *)data->mlx_img->pixels;
	width_sweep = -1;
	while (++width_sweep < (WIDTH * HEIGHT) / 2)
		*(mapc++) = *((uint32_t *)data->map->color_tab[1]);
	width_sweep--;
	while (++width_sweep < (WIDTH * HEIGHT))
		*(mapc++) = *((uint32_t *)data->map->color_tab);
	width_sweep = 0;
	start_rad = data->player->rad - (FOV / 2);
	gap_rad = FOV / WIDTH;
	while (width_sweep < WIDTH)
	{
		wall_size = send_ray(start_rad, data);
		render_wall(round(900 / wall_size), data, width_sweep, 0);
		width_sweep++;
		start_rad += gap_rad;
	}
}

void	cub3d(t_data *data)
{
	put_full_img(data);
	fill_minimap(data);
	mlx_image_to_window(data->mlx, data->mlx_img, 0, 0);
	mlx_image_to_window(data->mlx, data->minimap_img, 0, 0);
}

int	load_texture(t_data *data)
{
	data->texture = (t_pxtxtr *)malloc(sizeof(t_pxtxtr));
	if (!data->texture)
		return (1);
	if (data_struct_convert(&data->texture->no, data->map->txtr_tab[NO], data))
		return (1);
	if (data_struct_convert(&data->texture->so, data->map->txtr_tab[SO], data))
		return (1);
	if (data_struct_convert(&data->texture->ea, data->map->txtr_tab[EA], data))
		return (1);
	if (data_struct_convert(&data->texture->we, data->map->txtr_tab[WE], data))
		return (1);
	return (0);
}

static void	ft_hook_mov(void *param)
{
	t_data	*data;
	
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
	{
		set_newrad(data->player, MLX_KEY_LEFT);
		cub3d(data);
	}
	else if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
	{
		set_newrad(data->player, MLX_KEY_RIGHT);
		cub3d(data);
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_arg(&data, argc, argv))
		free_parse(&data);
	if (init_data(&data))
		free_data(&data);
	//mlx_close_hook(data.mlx, free_data, &data);
	cub3d(&data);
	//mlx_key_hook(data.mlx, key_hook_handler, &data);
	mlx_loop_hook(data.mlx, ft_hook_mov, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
