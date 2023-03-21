/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:11:30 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/21 13:09:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cellpos	get_new_pos(t_data *data, int direction)
{
	t_cellpos	rvalue;
	double		rad;

	rad = data->player->rad;
	rvalue = data->player->pos;
	if (direction == MLX_KEY_A || direction == MLX_KEY_D)
		rad += M_PI / 2;
	if (direction == MLX_KEY_W || direction == MLX_KEY_D)
		rvalue.x += cos(rad) / 8;
	else
		rvalue.x -= cos(rad) / 8;
	if (direction == MLX_KEY_W || direction == MLX_KEY_D)
		rvalue.y += sin(rad) / 8;
	else
		rvalue.y -= sin(rad) / 8;
	return (rvalue);
}

void	move_player(t_data *data, int direction)
{
	t_cellpos	new_pos;

	new_pos = get_new_pos(data, direction);
	if (data->map->map_tab[(int)(new_pos.y)][(int)(new_pos.x)] == '1')
		return ;
	else
		data->player->pos = new_pos;
}

void	set_newrad(t_player *player, int direction)
{
	double	step;

	step = 0.02;
	if (direction == MLX_KEY_RIGHT)
	{
		if (player->rad + step > (2 * M_PI))
			player->rad = 0;
		else
			player->rad += step;
	}
	else if (direction == MLX_KEY_LEFT)
	{
		if (player->rad - step < 0)
			player->rad = (2 * M_PI - step);
		else
			player->rad -= step;
	}
}

void	key_hook_handler(mlx_key_data_t keycode, void *datavoid)
{
	t_data	*data;

	data = (t_data *)datavoid;
	if (keycode.key == MLX_KEY_ESCAPE)
		free_data(data);
	else if (keycode.key == MLX_KEY_LEFT)
		set_newrad(data->player, MLX_KEY_LEFT);
	else if (keycode.key == MLX_KEY_RIGHT)
		set_newrad(data->player, MLX_KEY_RIGHT);
	else if (keycode.key == MLX_KEY_W || keycode.key == MLX_KEY_S
		|| keycode.key == MLX_KEY_A || keycode.key == MLX_KEY_D)
		move_player(data, keycode.key);
	cub3d(data);
	return ;
}
