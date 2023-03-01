/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reallaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:00:55 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/01 16:01:00 by reallaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

void	free_tab(void *str)
{
	int		i;
	char	**tab;

	tab = str;
	i = 0;
	if (tab == 0)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return ;
}

void	free_lst(t_char_lst *lst)
{
	t_char_lst	*temp;

	while (lst)
	{
		free(lst->line);
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

void	free_str(void *str)
{
	char	*value;

	value = str;
	if (value)
		return ;
	free(value);
	return ;
}

void	free_parse(void *data)
{
	t_data	*value;

	value = (t_data *)data;
	if (value)
	{
		if (value->texture)
			free(value->texture);
		if (value->map)
		{
			ft_free_strtab(value->map->map_tab);
			ft_free_strtab(value->map->txtr_tab);
		}
	}
	exit(1);
}

void	free_data(void *data)
{
	t_data	*value;

	value = (t_data *)data;
	if (value)
	{
		if (value->mlx)
		{
			if (value->mlx_img)
				mlx_delete_image(value->mlx, value->mlx_img);
			if (value->minimap_img)
				mlx_delete_image(value->mlx, value->minimap_img);
			mlx_terminate(value->mlx);
		}
		if (value->player)
			free(value->player);
		if (value->texture)
			free(value->texture);
		if (value->map)
		{
			ft_free_strtab(value->map->map_tab);
			ft_free_strtab(value->map->txtr_tab);
		}
	}
	exit(0);
}
