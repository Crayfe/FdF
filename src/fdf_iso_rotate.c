/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/08 15:25:15 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"
#include <math.h>

float	rotate_x(int x, int y, int z, int angle)
{
	float	rot_x;

	(void)z;
	rot_x = (x * cos(angle * (M_PI / 180.0)))
		- (y * sin(angle * (M_PI / 180.0)));
	return (rot_x);
}

float	rotate_y(int x, int y, int z, int angle)
{
	float	rot_y;

	(void)z;
	rot_y = (y * cos(angle * (M_PI / 180.0)))
		+ (x * sin(angle * (M_PI / 180.0)));
	return (rot_y);
}

float	get_proy_x(int x, int y, int z, int angle)
{
	float	proy_x;

	(void)z;
	proy_x = (rotate_x(x, y, z, angle)) - (rotate_y(x, y, z, angle));
	return (proy_x);
}

float	get_proy_y(int x, int y, int z, int angle)
{
	float	proy_y;

	proy_y = -((float)z / 2) + ((rotate_x(x, y, z, angle)
				+ rotate_y(x, y, z, angle)) / 2);
	return (proy_y);
}

void	compose_rotate(t_mlx_data *mlibx, t_dot *dot_iso, t_dot dot)
{
	t_model	*fdf;

	fdf = mlibx->fdf_model;
	dot_iso->x = mlibx->offset_x + ft_round(get_proy_x(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x],
				mlibx->angle));
	dot_iso->y = mlibx->offset_y + ft_round(get_proy_y(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x],
				mlibx->angle));
}
