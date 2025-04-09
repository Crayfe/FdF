/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <cayuso-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/04 08:59:07 by crayfe           ###   ########.fr       */
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

int	key_options(int key, t_mlx_data *mlibx)
{
	if (key == 65307)
		close_window(mlibx);
	else if (key == 65361)
		mlibx->angle += 1;
	else if (key == 65363)
		mlibx->angle -= 1;
	else if (key == 119)
		mlibx->offset_y += mlibx->scale;
	else if (key == 97)
		mlibx->offset_x += mlibx->scale;
	else if (key == 115)
		mlibx->offset_y -= mlibx->scale;
	else if (key == 100)
		mlibx->offset_x -= mlibx->scale;
	else if (key == 43)
		mlibx->scale += 1;
	else if (key == 45)
	{
		if (mlibx->scale > 1)
			mlibx->scale -= 1;
	}
	else
		return (0);
	return (1);
}

int	handle_keys(int key, t_mlx_data *mlibx)
{
	ft_printf("Key pressed: %i\n", key);
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
	set_bg_img(mlibx, 0);
	draw_fdf(mlibx);
	mlx_put_image_to_window(
		mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	return (0);
}
