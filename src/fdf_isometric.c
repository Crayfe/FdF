/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_isometric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 20:05:09 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

float	get_iso_x(int x, int y, int z)
{
	float	iso_x;

	(void)z;
	iso_x = x - y;
	return (iso_x);
}

float	get_iso_y(int x, int y, int z)
{
	float	iso_y;

	iso_y = -((float)z / 2) + ((float)(x + y) / 2);
	return (iso_y);
}

void	compose_iso(t_mlx_data *mlibx, t_dot *dot_iso, t_dot dot)
{
	t_model	*fdf;

	fdf = mlibx->fdf_model;
	dot_iso->x = mlibx->offset_x + ft_round(get_iso_x(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x]));
	dot_iso->y = mlibx->offset_y + ft_round(get_iso_y(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x]));
}
