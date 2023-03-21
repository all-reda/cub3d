/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:04:33 by reallaou          #+#    #+#             */
/*   Updated: 2023/03/21 13:31:41 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stdint.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# define WIDTH 1960
# define HEIGHT 860
# define FOV (1.0472)
# define ABS(x) (((x) < 0) ? -(x) : (x))
# define CELLSIZE 10

typedef struct s_cellpos
{
	double	x;
	double	y;
}	t_cellpos;

typedef enum e_cardinals
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
}	t_cardinals;

typedef struct s_ray
{
	double	size;
	double	theta;
	double	hyp_x;
	double	hyp_y;
	double	dep_x;
	double	dep_y;
	double	start_x;
	double	start_y;
	int		sign_x;
	int		sign_y;
}	t_ray;

typedef struct s_player
{
	t_cellpos	pos;
	double		rad;
	int			hit;
	double		hitp;
}	t_player;

typedef enum e_txtr
{
	NO,
	SO,
	WE,
	EA,
	F,
	C
}	t_txtr;

typedef struct s_char_lst
{
	char				*line;
	struct s_char_lst	*next;
}	t_char_lst;

typedef struct s_pxtxtr
{
	uint32_t	**no;
	uint32_t	**so;
	uint32_t	**ea;
	uint32_t	**we;
	int			txr;
}	t_pxtxtr;

typedef struct s_map
{
	char		*txtr_tab[5];
	uint8_t		color_tab[2][4];
	int			map_x;
	int			map_y;
	char		**map_tab;
}	t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*mlx_img;
	mlx_image_t	*minimap_img;
	t_map		*map;
	t_player	*player;
	t_pxtxtr	*texture;
}	t_data;

/* PARSING */

int			parse_arg(t_data *data, int argc, char **argv);
int			check_map(t_data *data);
int			parse_map(char *str, t_data *data);

/* INIT */

int			init_data(t_data *data);
int			new_lst_char(t_char_lst **list, char *str);
void		init_ray(t_ray *ray);

int			ft_error_free(char *str, void (*func)(void *), void *var);
int			ft_error_msg(char *str, int errno);

/* RENDER */
void		render_wall(int wall_height, t_data *data, int column, int i);
int			data_struct_convert(uint32_t ***dir,
				const char *path, t_data *data);
/* FREE */

void		free_tab(void *str);
void		free_str(void *str);
void		free_data(void *data);
void		free_lst(t_char_lst *lst);
void		free_parse(void *data);

/* UTILS */
double		send_ray(double rad, t_data *data);
int			load_texture(t_data *data);

int			ft_is_identifier(char *str, t_data *data);
int			ft_check_color(t_txtr txtr, char *str, t_data *data);
int			ft_load_txtr(t_txtr txtr, char *str, t_data *data);
char		*gnl_no_nl(int fd);
int			ft_is_blankline(const char *s1);
void		while_gnl(char **str, int fd);
int			line_fill(t_char_lst *lst, t_map *map, int j);
int			lst_to_tab_char(t_char_lst *lst, t_map *map);
int			check_map_inside(t_map *map);

t_cellpos	get_player_pos(char **map);
double		get_player_rad(char dir);

void		set_newrad(t_player *player, int direction);
void		key_hook_handler(mlx_key_data_t keycode, void *data);
mlx_image_t	*create_minimap(mlx_t *mlx, t_map *map);
void		put_player_minimap(mlx_image_t	*minimap_img, t_player *player);

void		move_player(t_data *data, int direction);
void		cub3d(t_data *data);
void		fill_minimap(t_data *data);
#endif
