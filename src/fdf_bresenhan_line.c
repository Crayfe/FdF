/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bresenhan.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/02 16:39:32 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

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
	static int i = 0;

	(void)colors;
	++i;
	ft_printf("line %i:\n");
	init_vars(&vars, dot0, dot1);
	ft_printf("dx = %i:\n", vars.dx);
	ft_printf("dy = %i:\n", vars.dy);
	while (1)
	{
		ft_printf("Dot\n");
		set_pixel(mlibx, 2147483647, dot0.x, dot0.y);
		if (dot0.x == dot1.x && dot0.y == dot1.y)
			break ;
		update_vars_and_dot(&vars, &dot0);
	}
}

