/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:49 by cayuso-f         ###   ########.fr       */
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
		//free(mlibx->img.img_pixels_ptr);
		free(mlibx->mlx_ptr);
		free_model(mlibx->fdf_model);
		exit(0);
	}
	/* 0xFF0000 */
	else if (key == 114)
	{
		set_bg_img(mlibx, 16711680);
		mlx_put_image_to_window(mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	/* 0x00FF00 */
	else if (key == 103)
	{
		set_bg_img(mlibx, 65280);
		mlx_put_image_to_window(mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	/* 0x0000FF */
	else if (key == 98)
	{
		set_bg_img(mlibx, 255);
		mlx_put_image_to_window(mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	return (0);
}

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
			offset = (mlibx->img.line_len * i) + (j * (mlibx->img.bits_per_pixel / 8));
			*((unsigned	int *)(offset + mlibx->img.img_pixels_ptr)) = color;
		}
	}
}

int	setup_win(t_mlx_data *mlibx)
{
	mlibx->mlx_ptr = mlx_init();
	if (!mlibx->mlx_ptr)
		return (1);
	mlibx->win_ptr = mlx_new_window(mlibx->mlx_ptr, HEIGHT, WIDTH, "FdF");
	if (!mlibx->win_ptr)
	{
		mlx_destroy_display(mlibx->mlx_ptr);
		free(mlibx->mlx_ptr);
		return (1);
	}
	mlibx->img.img_ptr = mlx_new_image(mlibx->mlx_ptr, HEIGHT, WIDTH);
	mlibx->img.img_pixels_ptr = mlx_get_data_addr(mlibx->img.img_ptr, &mlibx->img.bits_per_pixel, &mlibx->img.line_len, &mlibx->img.endian);
	mlx_key_hook(mlibx->win_ptr, handle_keys, mlibx);
	return (0);
}
