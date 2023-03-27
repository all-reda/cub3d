/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fl-hote <fl-hote@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:03:39 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/27 16:24:43 by fl-hote          ###   ########.fr       */
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

static void	ft_hook2(t_data *data, int move_key, int rot_key)
{
	if (rot_key)
		set_newrad(data->player, rot_key);
	if (move_key)
		move_player(data, move_key);
	if (move_key || rot_key)
		cub3d(data);
}

static void	ft_hook(void *param)
{
	t_data	*data;
	int		move_key;
	int		rot_key;

	move_key = 0;
	rot_key = 0;
	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rot_key = MLX_KEY_LEFT;
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rot_key = MLX_KEY_RIGHT;
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_key = MLX_KEY_A;
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_key = MLX_KEY_D;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_key = MLX_KEY_W;
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_key = MLX_KEY_S;
	ft_hook2(data, move_key, rot_key);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (parse_arg(&data, argc, argv))
		free_parse(&data);
	if (init_data(&data))
		free_data(&data);
	cub3d(&data);
	mlx_loop_hook(data.mlx, ft_hook, &data);
	mlx_loop(data.mlx);
	free_data(&data);
	return (0);
}
