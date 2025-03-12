/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_Minilib.c                                     :+:      :+:    :+:   */
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

	fdf_model = 0;
	if (argc == 1)
		fdf_model = load_model("model_files/pyramide.fdf");
	else if (argc == 2)
		fdf_model = load_model(argv[1]);
	if (!fdf_model)
		return (1);
	mlibx.fdf_model = fdf_model;
	print_model(fdf_model);
	if (setup_win(&mlibx) == 0)
	{
		mlx_loop(mlibx.mlx_ptr);
	}
	return (0);
}
