/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 19:56:39 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlibx;
	int			fd;

	if (argc != 2)
		ft_printf("\033[0;33mUsage: ./fdf <filename>\033[0m\n");
	else
	{
		fd = open(argv[1], 0);
		if (fd <= 0)
			return (ft_printf("\033[0;31mError: file \"%s\" does not exist\033[0m\n",argv[1]), 1);
		close(fd);
		mlibx.fdf_model = load_model(argv[1]);
		mlibx.offset_x = WIDTH / 2;
		mlibx.offset_y = HEIGHT / 4;
		mlibx.scale = SCALE;
		mlibx.angle = 0;
		if (!mlibx.fdf_model)
			return (ft_printf("\033[0;31mError loding model \"%s\"\033[0m\n", argv[1]), 1);
		if (setup_win(&mlibx) == 0)
			mlx_loop(mlibx.mlx_ptr);
	}
	return (0);
}
