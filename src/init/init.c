/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:02:45 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:02:49 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_player(t_data *data)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (0);
	player->pos = get_player_pos(data->map->map_tab);
	if (player->pos.x == -1)
		return (0);
	player->rad = get_player_rad(data->map->map_tab[(int)player->pos.y] \
		[(int)player->pos.x]);
	player->hit = -1;
	player->hitp = 0;
	data->player = player;
	return (1);
}

void	init_ray(t_ray *ray)
{
	ray->size = 0;
	ray->theta = 0;
	ray->hyp_x = 0;
	ray->hyp_y = 0;
	ray->dep_x = 0;
	ray->dep_y = 0;
	ray->start_x = 0;
	ray->start_y = 0;
	ray->sign_x = 1;
	ray->sign_y = 1;
}

int	init_data(t_data *data)
{
	data->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	if (!data->mlx)
		return (ft_error_free("MLX Init Fail", &free_data, data));
	data->mlx_img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	if (!data->mlx_img)
		return (ft_error_free("MLX Image Init Fail", &free_data, data));
	if (!init_player(data))
		return (ft_error_free("Player Init Fail", &free_data, data));
	data->minimap_img = create_minimap(data->mlx, data->map);
	if (!data->minimap_img)
		return (ft_error_free("Minimap Init Fail", &free_data, data));
	if (load_texture(data))
		return (ft_error_msg("Texture load Fail", 1));
	return (0);
}

int	new_lst_char(t_char_lst **list, char *str)
{
	t_char_lst	*element;
	t_char_lst	*lst;

	element = (t_char_lst *)malloc(sizeof(t_char_lst));
	if (!element)
		return (1);
	lst = *list;
	element->line = str;
	element->next = 0;
	if (lst)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = element;
	}
	else
		*list = element;
	return (0);
}
