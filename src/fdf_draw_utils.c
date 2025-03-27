/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/25 08:15:38 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_dots(t_mlx_data *mlibx, t_model *fdf)
{
	int	x;
	int	y;
	int	x_iso;
	int	y_iso;

	y = 0;
	while (y < fdf->num_rows)
	{
		x = 0;
		while (x < fdf->num_cols)
		{
			x_iso = WIDTH / 2 + (int)get_iso_x(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			y_iso = HEIGHT / 4 + (int)get_iso_y(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			if ((x_iso >= 0 && x_iso <= WIDTH)
					&& (y_iso >= 0 && y_iso <= HEIGHT)) 
				set_pixel(mlibx, 0xFFFFFF, x_iso, y_iso);
			++x;
		}
		++y;
	}
}

void    draw_line(t_mlx_data *mlibx, int x0, int y0, int x1, int y1)
{
	int dx =  ft_abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -ft_abs(y1 - y0), sy = y0 < y1 ? 1 : -1; 
	int err = dx + dy, e2; /* error value e_xy */

	while (1)
	{
		set_pixel (mlibx, 2147483647,x0,y0);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy) { err += dy; x0 += sx; } /* e_xy+e_x > 0 */
		if (e2 <= dx) { err += dx; y0 += sy; } /* e_xy+e_y < 0 */
	}
}

void	draw_x_axis(t_mlx_data *mlibx, t_model *fdf)
{
	int	x;
	int	y;
	int	x_iso;
	int	y_iso;
	int	x_iso1;
	int	y_iso1;

	y = 0;
	while (y < fdf->num_rows)
	{
		x = 0;
		x_iso = WIDTH / 2 + (int)get_iso_x(SCALE * x,
			SCALE * y, SCALE * fdf->model[y][x]);
		y_iso = HEIGHT / 4 + (int)get_iso_y(SCALE * x,
			SCALE * y, SCALE * fdf->model[y][x]);
		while (++x < fdf->num_cols)
		{
			x_iso1 = WIDTH / 2 + (int)get_iso_x(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			y_iso1 = HEIGHT / 4 + (int)get_iso_y(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			draw_line(mlibx, x_iso, y_iso, x_iso1, y_iso1);
			x_iso = x_iso1;
			y_iso = y_iso1;
		}
		++y;
	}
}

void	draw_y_axis(t_mlx_data *mlibx, t_model *fdf)
{
	int	x;
	int	y;
	int	x_iso;
	int	y_iso;
	int	x_iso1;
	int	y_iso1;

	x = 0;
	while (x < fdf->num_cols)
	{
		y = 0;
		x_iso = WIDTH / 2 + (int)get_iso_x(SCALE * x,
			SCALE * y, SCALE * fdf->model[y][x]);
		y_iso = HEIGHT / 4 + (int)get_iso_y(SCALE * x,
			SCALE * y, SCALE * fdf->model[y][x]);
		while (++y < fdf->num_rows)
		{
			x_iso1 = WIDTH / 2 + (int)get_iso_x(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			y_iso1 = HEIGHT / 4 + (int)get_iso_y(SCALE * x,
					SCALE * y, SCALE * fdf->model[y][x]);
			draw_line(mlibx, x_iso, y_iso, x_iso1, y_iso1);
			x_iso = x_iso1;
			y_iso = y_iso1;
		}
		++x;
	}
}
