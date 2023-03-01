/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:14:59 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:15:16 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_cellpos	get_cellpos(t_cellpos pos)
{
	t_cellpos	rvalue;

	rvalue.x = pos.x - (int)pos.x;
	rvalue.y = pos.y - (int)pos.y;
	return (rvalue);
}

void	setup_ray(t_ray *ray, double rad, t_cellpos cell_pos)
{
	ray->theta = rad - floor(rad / (2 * M_PI)) * (2 * M_PI);
	ray->sign_x = round(cos(ray->theta) / ABS(cos(ray->theta)));
	ray->sign_y = round(sin(ray->theta) / ABS(sin(ray->theta)));
	if (!cos(ray->theta))
		ray->sign_x = 0;
	else if (!sin(ray->theta))
		ray->sign_y = 0;
	ray->hyp_x = 1 / cos(ray->theta);
	ray->hyp_y = 1 / sin(ray->theta);
	ray->dep_x = ABS(1 / (tan(ray->theta))) * ray->sign_x;
	if (rad == 0)
		ray->dep_y = 0;
	else
		ray->dep_y = ABS(tan(ray->theta)) * ray->sign_y;
	ray->start_x = ABS(ray->hyp_x * (1 - cell_pos.x));
	ray->start_y = ABS(ray->hyp_y * (1 - cell_pos.y));
	if (ray->theta > M_PI)
		ray->start_y = ABS(ray->hyp_y * (cell_pos.y));
	if (ray->theta > M_PI_2 && ray->theta < 3 * M_PI_2)
		ray->start_x = ABS(ray->hyp_x * (cell_pos.x));
}

void	check_wall(t_ray *ray, t_map *map, t_cellpos *p)
{
	while (p[0].y < map->map_y && p[1].x < map->map_x)
	{
		if (ABS(ray->start_y) < ABS(ray->start_x))
		{
			if (map->map_tab[(int)(p[0].y + ray->sign_y)][(int)p[0].x] == '1')
				break ;
			p[0].y = (int)(p[0].y + ray->sign_y);
			ray->start_y += (ray->hyp_y * ray->sign_y);
			p[0].x += ray->dep_x;
		}
		else
		{
			if (map->map_tab[(int)p[1].y][(int)(p[1].x + ray->sign_x)] == '1')
				break ;
			p[1].x = (int)(p[1].x + ray->sign_x);
			ray->start_x += (ray->hyp_x * ray->sign_x);
			p[1].y += ray->dep_y;
		}
	}
}

void	collision(t_ray *ray, t_cellpos pos, t_data *data)
{
	t_cellpos	p[2];

	p[0].x = pos.x + (ray->start_y * cos(ray->theta));
	p[0].y = pos.y;
	p[1].x = pos.x;
	p[1].y = pos.y + (ray->start_x * sin(ray->theta));
	check_wall(ray, data->map, p);
	if (ABS(ray->start_y) < ABS(ray->start_x))
	{
		ray->size = ABS(ray->start_y);
		data->player->hitp = p[0].x - (int)p[0].x;
		if (ray->sign_y < 0)
			data->player->hit = 0;
		else
			data->player->hit = 1;
	}
	else
	{
		ray->size = ABS(ray->start_x);
		data->player->hitp = p[1].y - (int)p[1].y;
		if (ray->sign_x < 0)
			data->player->hit = 2;
		else
			data->player->hit = 3;
	}
}

double	send_ray(double rad, t_data *data)
{
	t_ray	ray;
	double	delta_angle;

	init_ray(&ray);
	setup_ray(&ray, rad, get_cellpos(data->player->pos));
	collision(&ray, data->player->pos, data);
	delta_angle = data->player->rad - ray.theta;
	ray.size = ABS(ray.size * cos(delta_angle));
	return (ray.size);
}
