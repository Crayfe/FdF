/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenhan_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 20:14:17 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_triple(int d0, int d1)
{
	int	s;

	if (d0 < d1)
		s = 1;
	else
		s = -1;
	return (s);
}

void	init_vars(t_bsh *vars, t_dot dot0, t_dot dot1)
{
	vars->dx = ft_abs(dot1.x - dot0.x);
	vars->dy = -ft_abs(dot1.y - dot0.y);
	vars->err1 = vars->dx + vars->dy;
	vars->sx = get_triple(dot0.x, dot1.x);
	vars->sy = get_triple(dot0.y, dot1.y);
}

int	get_color_step(t_bsh vars)
{
	if (ft_abs(vars.dx) >= ft_abs(vars.dy))
		return (ft_abs(vars.dx));
	return (ft_abs(vars.dy));
}

void	update_vars_and_dot(t_bsh *vars, t_dot *dot0)
{
	vars->err2 = 2 * vars->err1;
	if (vars->err2 >= vars->dy)
	{
		vars->err1 += vars->dy;
		dot0->x += vars->sx;
	}
	if (vars->err2 <= vars->dx)
	{
		vars->err1 += vars->dx;
		dot0->y += vars->sy;
	}
}

void	draw_bresenhan_line(t_mlx_data *mlibx, t_dot dot0, t_dot dot1,
		t_colors colors)
{
	t_bsh	vars;
	int		color;
	int		i;

	i = 0;
	init_vars(&vars, dot0, dot1);
	color = colors.color0;
	colors.step = get_color_step(vars);
	while (1)
	{
		set_pixel(mlibx, color, dot0.x, dot0.y);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		update_vars_and_dot(&vars, &dot0);
		color = get_gradient_color(colors, i);
		i++;
	}
}
