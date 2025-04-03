/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 20:12:08 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/libft.h"
#include "../minilibx/mlx.h"
#include <fcntl.h>
#define WIDTH   1000
#define HEIGHT  800
#define SCALE	30

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_model_data
{
	int	**model;
	int	**colors;
	int	num_rows;
	int	num_cols;
}	t_model;

typedef struct s_mlx_data
{
	void				*mlx_ptr;
	void				*win_ptr;
	t_model				*fdf_model;
	t_img				img;
	int					offset_x;
	int					offset_y;
	unsigned int		scale;

}	t_mlx_data;

typedef struct s_dot
{
	int	x;
	int	y;
}	t_dot;

typedef struct s_colors
{
	int	color0;
	int	color1;
	int	step;
}	t_colors;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_bsh
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err1;
	int	err2;

}	t_bsh;

/* fdf_model_utils.c */
int		get_num_cols(char *file);
int		get_num_rows(char *file);
t_model	*load_model(char *model_file);
void	free_model(t_model	*m);

/* fdf_window_utils.c */
int		handle_keys(int key, t_mlx_data *mlibx);
int		setup_win(t_mlx_data *mlibx);

/* fdf_image_utils.c */
void	set_pixel(t_mlx_data *mlibx, int color, int x, int y);
void	set_bg_img(t_mlx_data *mlibx, int color);

/* fdf_isometric.c */
void	compose_iso(t_mlx_data *mlibx, t_dot *dot_iso, t_dot dot);

/* fdf_cavalier.c */
void	compose_cab(t_mlx_data *mlibx, t_dot *dot_iso, t_dot dot);

/* fdf_draw_utils.c */
void	draw_iso_dots(t_mlx_data *mlibx, t_model *fdf);
void	draw_fdf(t_mlx_data *mlibx);

/* fdf_besenhan_line.c */
void	draw_bresenhan_line(t_mlx_data *mlibx, t_dot dot0, t_dot dot1,
			t_colors colors);

/* fdf_colors.c*/
int		read_color(char *data);
int		parse_color(char *raw_color);
int		get_gradient_color(t_colors colors, int i);

/* fdf_debug_utils.c */
void	print_model(t_model *m);
void	print_colors(t_model *m);
