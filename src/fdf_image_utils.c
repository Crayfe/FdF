/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/25 08:13:52 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

void	set_bg_img(t_mlx_data *mlibx, int color)
{
	int	i;
	int	j;
	int	offset;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			offset = (mlibx->img.line_len * i)
				+ (j * (mlibx->img.bits_per_pixel / 8));
			*((unsigned int *)(offset + mlibx->img.img_pixels_ptr)) = color;
		}
	}
}

void	set_pixel(t_mlx_data *mlibx, int color, int x, int y)
{
	int	offset;

	if ((x >= 0 && x <= WIDTH) && (y >= 0 && y <= HEIGHT))
	{
		offset = (mlibx->img.line_len * y)
			+ (x * (mlibx->img.bits_per_pixel / 8));
		*((unsigned int *)(offset + mlibx->img.img_pixels_ptr)) = color;
	}
}