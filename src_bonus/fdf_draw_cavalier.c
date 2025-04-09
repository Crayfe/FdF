/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw_cavalier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/09 19:14:01 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_x_cav(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot		dot;
	t_dot		dot_iso0;
	t_dot		dot_iso1;
	t_colors	colors;

	dot.y = 0;
	while (dot.y < fdf->num_rows)
	{
		dot.x = 0;
		compose_cav(mlibx, &dot_iso0, dot);
		while (dot.x < fdf->num_cols - 1)
		{
			colors.color0 = fdf->colors[dot.y][dot.x];
			++dot.x;
			colors.color1 = fdf->colors[dot.y][dot.x];
			compose_cav(mlibx, &dot_iso1, dot);
			draw_bresenhan_line(mlibx, dot_iso0, dot_iso1, colors);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.y;
	}
}

void	draw_y_cav(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot		dot;
	t_dot		dot_iso0;
	t_dot		dot_iso1;
	t_colors	colors;

	dot.x = 0;
	while (dot.x < fdf->num_cols)
	{
		dot.y = 0;
		compose_cav(mlibx, &dot_iso0, dot);
		while (dot.y < fdf->num_rows - 1)
		{
			colors.color0 = fdf->colors[dot.y][dot.x];
			++dot.y;
			colors.color1 = fdf->colors[dot.y][dot.x];
			compose_cav(mlibx, &dot_iso1, dot);
			draw_bresenhan_line(mlibx, dot_iso0, dot_iso1, colors);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.x;
	}
}

void	draw_fdf_cav(t_mlx_data *mlibx)
{
	draw_x_cav(mlibx, mlibx->fdf_model);
	draw_y_cav(mlibx, mlibx->fdf_model);
}
