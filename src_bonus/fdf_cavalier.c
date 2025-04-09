/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_cavalier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 19:55:44 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	get_cab_x(int x, int y, int z)
{
	float	iso_x;

	(void)z;
	iso_x = (float)(x - y) / 2;
	return (iso_x);
}

float	get_cab_y(int x, int y, int z)
{
	float	iso_y;

	(void)x;
	iso_y = -((float)(z - y / 2));
	return (iso_y);
}

void	compose_cab(t_mlx_data *mlibx, t_dot *dot_iso, t_dot dot)
{
	t_model	*fdf;

	fdf = mlibx->fdf_model;
	dot_iso->x = mlibx->offset_x + ft_round(get_cab_x(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x]));
	dot_iso->y = mlibx->offset_y + ft_round(get_cab_y(mlibx->scale * dot.x,
				mlibx->scale * dot.y, mlibx->scale * fdf->model[dot.y][dot.x]));
}
