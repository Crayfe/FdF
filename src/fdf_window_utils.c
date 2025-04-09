/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/09 16:39:32 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	close_window(t_mlx_data *mlibx)
{
	mlx_destroy_image(mlibx->mlx_ptr, mlibx->img.img_ptr);
	mlx_destroy_window(mlibx->mlx_ptr, mlibx->win_ptr);
	mlx_destroy_display(mlibx->mlx_ptr);
	free(mlibx->mlx_ptr);
	free_model(mlibx->fdf_model);
	exit(0);
}

int	close_w(t_mlx_data *mlibx)
{
	return (close_window(mlibx), 0);
}

int	key_options(int key, t_mlx_data *mlibx)
{
	if (key == 65307)
		close_window(mlibx);
	else
		return (0);
	return (1);
}

int	handle_keys(int key, t_mlx_data *mlibx)
{
	if (key_options(key, mlibx))
	{
		set_bg_img(mlibx, 0);
		draw_fdf(mlibx);
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
	mlibx->win_ptr = mlx_new_window(mlibx->mlx_ptr, WIDTH, HEIGHT,
			"FdF by cayuso-f");
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
	mlx_hook(mlibx->win_ptr, 17, 0xFFFFFF, close_w, mlibx);
	set_bg_img(mlibx, 0);
	draw_fdf(mlibx);
	mlx_put_image_to_window(
		mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	return (0);
}
