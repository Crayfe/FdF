/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/24 17:57:23 by cayuso-f         ###   ########.fr       */
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

void	draw_line(t_mlx_data *mlibx, int *dot0, int *dot1)
{
	int dx =  ft_abs(dot1[0] - dot0[0]);
	int sx = dot0[0] < dot1[0] ? 1 : -1;
	int dy = -ft_abs(dot1[1] - dot0[1]);
	int sy = dot1[1] < dot0[1] ? 1 : -1; 
	int err = dx + dy, e2;
	
	while (1)
	{
		set_Pixel (mlibx, x0, y0);
		if (x0 == x1 && y0 == y1) break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		}
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		}
	}
}
