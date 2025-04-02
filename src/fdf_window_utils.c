/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/25 08:13:52 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	handle_keys(int key, t_mlx_data *mlibx)
{
	ft_printf("Key pressed: %i\n", key);
	if (key == 65307)
	{
		mlx_destroy_image(mlibx->mlx_ptr, mlibx->img.img_ptr);
		mlx_destroy_window(mlibx->mlx_ptr, mlibx->win_ptr);
		mlx_destroy_display(mlibx->mlx_ptr);
		free(mlibx->mlx_ptr);
		free_model(mlibx->fdf_model);
		exit(0);
	}
	else if (key == 114)
	{
		set_bg_img(mlibx, 16711680);
		draw_iso_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 103)
	{
		set_bg_img(mlibx, 65280);
		draw_iso_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 98)
	{
		set_bg_img(mlibx, 255);
		draw_fdf(mlibx);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 99)
	{
		set_bg_img(mlibx, 0);
		draw_iso_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	return (0);
}

int	setup_win(t_mlx_data *mlibx)
{
	mlibx->mlx_ptr = mlx_init();
	if (!mlibx->mlx_ptr)
		return (1);
	mlibx->win_ptr = mlx_new_window(mlibx->mlx_ptr, WIDTH, HEIGHT, "FdF");
	if (!mlibx->win_ptr)
	{
		mlx_destroy_display(mlibx->mlx_ptr);
		free(mlibx->mlx_ptr);
		return (1);
	}
	mlibx->img.img_ptr = mlx_new_image(mlibx->mlx_ptr, WIDTH, HEIGHT);
	mlibx->img.img_pixels_ptr = mlx_get_data_addr(mlibx->img.img_ptr,
			&mlibx->img.bits_per_pixel, &mlibx->img.line_len,
			&mlibx->img.endian);
	mlx_key_hook(mlibx->win_ptr, handle_keys, mlibx);
	return (0);
}
