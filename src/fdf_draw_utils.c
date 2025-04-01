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

int	is_drawable(t_dot dot)
{
	int	drawable;

	drawable = 0;
	if ((dot.x >= 0 && dot.x <= WIDTH) && (dot.y >= 0 && dot.y <= HEIGHT))
		drawable = 1;
	return (drawable);
}

void	draw_dots(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot	dot;
	t_dot	dot_iso;

	dot.y = 0;
	while (dot.y < fdf->num_rows)
	{
		dot.x = 0;
		while (dot.x < fdf->num_cols)
		{
			dot_iso.x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			dot_iso.y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			set_pixel(mlibx, fdf->colors[dot.y][dot.x], dot_iso.x, dot_iso.y);
			++dot.x;
		}
		++dot.y;
	}
}

int	get_triple(int d0, int d1)
{
	int	s;

	if (d0 < d1)
		s = 1;
	else
		s = -1;
	return (s);
}

void	draw_line(t_mlx_data *mlibx, t_dot dot0, t_dot dot1)
{
	t_bsh	vars;

	vars.dx = ft_abs(dot1.x - dot0.x);
	vars.dy = -ft_abs(dot1.y - dot0.y);
	vars.err1 = vars.dx + vars.dy;
	vars.sx = get_triple(dot0.x, dot1.x);
	vars.sy = get_triple(dot0.y, dot1.y);
	while (1)
	{
		set_pixel(mlibx, 2147483647, dot0.x, dot0.y);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		vars.err2 = 2 * vars.err1;
		if (vars.err2 >= vars.dy)
		{
			vars.err1 += vars.dy;
			dot0.x += vars.sx;
		}
		if (vars.err2 <= vars.dx)
		{
			vars.err1 += vars.dx;
			dot0.y += vars.sy;
		}
	}
}

void	draw_x_axis(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot	dot;
	t_dot	dot_iso0;
	t_dot	dot_iso1;

	dot.y = 0;
	while (dot.y < fdf->num_rows)
	{
		dot.x = 0;
		dot_iso0.x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
					SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
		dot_iso0.y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
					SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
		while (++dot.x < fdf->num_cols)
		{
			dot_iso1.x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			dot_iso1.y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			draw_line(mlibx, dot_iso0, dot_iso1);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.y;
	}
}

void	draw_y_axis(t_mlx_data *mlibx, t_model *fdf)
{
	t_dot	dot;
	t_dot	dot_iso0;
	t_dot	dot_iso1;

	dot.x = 0;
	while (dot.x < fdf->num_cols)
	{
		dot.y = 0;
		dot_iso0.x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
					SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
		dot_iso0.y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
					SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
		while (++dot.y < fdf->num_rows)
		{
			dot_iso1.x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			dot_iso1.y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
						SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
			draw_line(mlibx, dot_iso0, dot_iso1);
			dot_iso0.x = dot_iso1.x;
			dot_iso0.y = dot_iso1.y;
		}
		++dot.x;
	}
}
