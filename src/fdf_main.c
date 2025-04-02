/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:49 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FdF.h"

int	main(int argc, char **argv)
{
	t_mlx_data	mlibx;
	int			fd;

	if (argc != 2)
		ft_printf("Usage: ./fdf <filename>");
	else
	{
		fd = open(argv[1], 0);
		if (fd <= 0)
			return (ft_printf("Error: file %s does not exist\n", argv[1]), 1);
		close(fd);
		mlibx.fdf_model = load_model(argv[1]);
		mlibx.height = HEIGHT;
		mlibx.width = WIDTH;
		mlibx.scale = SCALE;
		if (!mlibx.fdf_model)
			return (ft_printf("Error loding model\n", argv[1]), 1);
	}
	print_model(mlibx.fdf_model);
	ft_printf("\n");
	print_colors(mlibx.fdf_model);
	if (setup_win(&mlibx) == 0)
		mlx_loop(mlibx.mlx_ptr);
	return (0);
}
