/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/01 17:12:09 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/src/libft.h"
#include "../minilibx/mlx.h"
//#include "../minilibx/mlx_int.h"
#define WIDTH   800
#define HEIGHT  600
#define SCALE	10

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
	void	*mlx_ptr;
	void	*win_ptr;
	t_model	*fdf_model;
	t_img	img;
}	t_mlx_data;

typedef struct s_dot
{
	int	x;
	int	y;
}	t_dot;

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
void	print_model(t_model *m);
void	print_colors(t_model *m);
/* fdf_window_utils.c */
void	set_pixel(t_mlx_data *mlibx, int color, int x, int y);
void	set_bg_img(t_mlx_data *mlibx, int color);

float	get_iso_x(int x, int y, int z);
float	get_iso_y(int x, int y, int z);
int		handle_keys(int key, t_mlx_data *mlibx);
int		setup_win(t_mlx_data *mlibx);
/* fdf_window_utils.c */
int		is_drawable(t_dot dot);
void	draw_dots(t_mlx_data *mlibx, t_model *fdf);
void	draw_line(t_mlx_data *mlibx, t_dot dot0, t_dot dot1);
void	draw_x_axis(t_mlx_data *mlibx, t_model *fdf);
void	draw_y_axis(t_mlx_data *mlibx, t_model *fdf);
