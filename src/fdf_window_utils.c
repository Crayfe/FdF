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
		mlx_destroy_window(mlibx->mlx_ptr, mlibx->win_ptr);
		mlx_destroy_display(mlibx->mlx_ptr);
		free(mlibx->mlx_ptr);
		exit(0);
	}
	return (0);
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
	mlx_key_hook(mlibx->win_ptr, handle_keys, mlibx);
	return (0);
}
