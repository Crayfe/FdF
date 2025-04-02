/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/01 18:03:03 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	draw_iso_dots(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot	dot;
	t_dot	dot_iso;

	dot.y = 0;
	while (dot.y < fdf->num_rows)
	{
		dot.x = 0;
		while (dot.x < fdf->num_cols)
		{
			compose_iso(mlibx, &dot_iso, dot);
			set_pixel(mlibx, fdf->colors[dot.y][dot.x], dot_iso.x, dot_iso.y);
			++dot.x;
		}
		++dot.y;
	}
}

void	draw_x_axis(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot		dot;
	t_dot		dot_iso0;
	t_dot		dot_iso1;
	t_colors	colors;

	dot.y = 0;
	while (dot.y < fdf->num_rows)
	{
		dot.x = 0;
		colors.color0 = fdf->colors[dot.y][dot.y];
		compose_iso(mlibx, &dot_iso0, dot);
		while (++dot.x < fdf->num_cols)
		{
			compose_iso(mlibx, &dot_iso1, dot);
			colors.color1 = fdf->colors[dot.y][dot.y];
			draw_bresenhan_line(mlibx, dot_iso0, dot_iso1, colors);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.y;
	}
}

void	draw_y_axis(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot		dot;
	t_dot		dot_iso0;
	t_dot		dot_iso1;
	t_colors	colors;

	dot.x = 0;
	while (dot.x < fdf->num_cols)
	{
		dot.y = 0;
		colors.color0 = fdf->colors[dot.y][dot.y];
		compose_iso(mlibx, &dot_iso0, dot);
		while (++dot.y < fdf->num_rows)
		{
			compose_iso(mlibx, &dot_iso1, dot);
			colors.color1 = fdf->colors[dot.y][dot.y];
			draw_bresenhan_line(mlibx, dot_iso0, dot_iso1, colors);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.x;
	}
}

void	draw_fdf(t_mlx_data *mlibx)
{
	draw_x_axis(mlibx, mlibx->fdf_model);
	draw_y_axis(mlibx, mlibx->fdf_model);
}
