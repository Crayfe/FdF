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
	t_model		*fdf_model;
	int			fd;

	fdf_model = 0;
	if (argc != 2)
		ft_printf("Usage: ./fdf <filename>");
	else
	{
		fd = open(argv[1], 0);
		if (fd <= 0)
			return (ft_printf("Error: file %s does not exist\n", argv[1]), 1);
		close(fd);
		fdf_model = load_model(argv[1]);
		if (!fdf_model)
			return (ft_printf("Error loding model\n", argv[1]), 1);
	}
	mlibx.fdf_model = fdf_model;
	print_model(fdf_model);
	ft_printf("\n");
	print_colors(fdf_model);
	if (setup_win(&mlibx) == 0)
		mlx_loop(mlibx.mlx_ptr);
	return (0);
}
