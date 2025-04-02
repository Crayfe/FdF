/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_iso_proyect.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/02 18:18:37 by cayuso-f         ###   ########.fr       */
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
	dot_iso->x = WIDTH / 2 + ft_round(get_iso_x(SCALE * dot.x,
				SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
	dot_iso->y = HEIGHT / 4 + ft_round(get_iso_y(SCALE * dot.x,
				SCALE * dot.y, SCALE * fdf->model[dot.y][dot.x]));
}