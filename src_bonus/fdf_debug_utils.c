/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_debug_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <causo-f@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 19:58:29 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_model(t_model *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->num_rows)
	{
		j = 0;
		while (j < fdf->num_cols)
		{
			ft_printf("%i ", fdf->model[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_colors(t_model *fdf)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->num_rows)
	{
		j = 0;
		while (j < fdf->num_cols)
		{
			ft_printf("%i ", fdf->colors[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
