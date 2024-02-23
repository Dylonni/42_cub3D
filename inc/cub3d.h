/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daumis <daumis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:21:30 by mba               #+#    #+#             */
/*   Updated: 2024/02/23 12:31:18 by daumis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 	640
# define WIN_HEIGHT 480
# define TEX_SIZE 	64
# define MOVESPEED	0.0125
# define ROTATESPEED	0.015	

/* --- KEYS  DEFINE --- */

# define KEY_FORWARD	119
# define KEY_BACK		115
# define KEY_RIGHT		100
# define KEY_LEFT		97
# define KEY_ARR_L		65361
# define KEY_ARR_R		65363
# define KEY_ESC		65307

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		pixel_bits;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texinfo
{
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	int				*floor;
	int				*ceiling;
	unsigned long	hex_floor;
	unsigned long	hex_ceiling;
	int				size;
	int				index;
	double			step;
	double			pos;
	int				x;
	int				y;
}	t_texinfo;

typedef struct s_ray
{
	double	camera;
	double	dir_x;
	double	dir_y;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	wall_dist;
	double	wall_x;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_ray;

typedef struct s_mapinfo
{
	int		fd;
	int		line_count;
	char	*path;
	char	**file;
	int		height;
	int		width;
	int		index_end_map;
}	t_mapinfo;

typedef struct s_player
{
	char	dir;
	double	pos_x;
	double	pos_y;
	double	plane_x;
	double	plane_y;
	double	dir_x;
	double	dir_y;
	int		rotate;
	int		go_x;
	int		go_y;
	int		has_moved;
}	t_player;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			win_height;
	int			win_width;
	int			first_render;
	char		**map;
	t_player	player;
	t_mapinfo	mapinfo;
	t_texinfo	texinfo;
	t_img		minimap;
	t_ray		ray;
	int			**texture_pixels;
	int			**textures;
}	t_data;

/*parsing*/
int		check_file(char *arg);
void	parse_data(char *path, t_data *data);
int		read_data(t_data *data, char **map);
int		fill_color_textures(t_texinfo *textures,
			char *line, int j);
int		create_map(t_data *data, char **file, int i);
int		check_map_sides(t_mapinfo *map, char **map_tab);
int		check_map_validity(t_data *data, char **map_tab);
int		check_textures_validity(t_texinfo *textures);
int		check_extension_xpm(char *arg);

/*init*/
void	init_data(t_data *data);
void	exit_clean(t_data *data);
void	init_img_clean(t_img *img);
void	init_raycaster(t_ray *ray);
void	init_player_direction(t_data *data);
void	init_texture_img(t_data *data, t_img *image, char *path);
void	init_img(t_data *data, t_img *image, int width, int height);

/*exit*/
void	free_tab(void **tab);
int		free_data(t_data *data);
void	exit_clean(t_data *data);
int		exit_game(t_data *data);

/* debug/debug.c */
void	debug_print_char_tab(char **tab);

/* utils */
int		find_biggest_len(t_mapinfo *mao, int i);
int		is_a_white_space(char c);
void	close_map(t_data *data, char **map);
/* draw */
int		render_images(t_data *data);
void	init_texture_pixels(t_data *data);
void	update_texture_pixels(t_data *data, t_texinfo *tex, t_ray *ray, int x);
void	init_textures(t_data *data);
void	set_image_pixel(t_img *image, int x, int y, int color);
int		raycast(t_player *player, t_data *data);

/* mouv */
void	input_handler(t_data *data);
int		move(t_data *data);
int		rotate(t_data *data, double rot_direction);
int		validate_move(t_data *data, double new_x, double new_y);

#endif
