/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_window_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/23 20:12:20 by crayfe           ###   ########.fr       */
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
	else if (key == 114)
	{
		set_bg_img(mlibx, 16711680);
		draw_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 103)
	{
		set_bg_img(mlibx, 65280);
		draw_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 98)
	{
		set_bg_img(mlibx, 255);
		draw_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
	}
	else if (key == 99)
	{
		set_bg_img(mlibx, 0);
		draw_dots(mlibx, mlibx->fdf_model);
		mlx_put_image_to_window(
			mlibx->mlx_ptr, mlibx->win_ptr, mlibx->img.img_ptr, 0, 0);
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
			offset = (mlibx->img.line_len * i)
				+ (j * (mlibx->img.bits_per_pixel / 8));
			*((unsigned int *)(offset + mlibx->img.img_pixels_ptr)) = color;
		}
	}
}

void	set_pixel(t_mlx_data *mlibx, int color, int x, int y)
{
	int	offset;

	offset = (mlibx->img.line_len * y)
		+ (x * (mlibx->img.bits_per_pixel / 8));
	*((unsigned int *)(offset + mlibx->img.img_pixels_ptr)) = color;
}
void	draw_dots(t_mlx_data *mlibx, t_model *fdf)
{
	int	x;
	int	y;
	int x_iso;
	int y_iso;

	y = 0;
	while (y < fdf->num_rows)
	{
		x = 0;
		while (x < fdf->num_cols)
		{
			x_iso = WIDTH/2 + (int)get_iso_x(10 * x, 10 * y, fdf->model[y][x]);
			y_iso = HEIGHT/4  + (int)get_iso_y(10 * x, 10 * y, 10 * fdf->model[y][x]);
			ft_printf("%i ", fdf->model[y][x]);
			if ((x_iso >= 0 && x_iso <= WIDTH) && (y_iso >= 0 && y_iso <= HEIGHT)) 
				set_pixel(mlibx, 0xFFFFFF, x_iso, y_iso);
			++x;
		}
		++y;
	}
}

float	get_iso_x(int x, int y, int z)
{
	float	iso_x;

	(void)z;
	iso_x = x - y;
	//iso_x = ((float)x * 0.8660254) - ((float)y * 0.5) - ((float)z * 0.5);
	return (iso_x);
}

float	get_iso_y(int x, int y, int z)
{
	float	iso_y;

	iso_y = -((float)z/ 2) + ((float)(x + y) / 2);
	//iso_y = ((float)x * 0.5) - ((float)y * 0.8660254) - ((float)z * 0.8660254);
	return (iso_y);
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
