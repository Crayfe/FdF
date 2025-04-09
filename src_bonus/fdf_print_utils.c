/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_print_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <causo-f@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/09 19:14:41 by cayuso-f         ###   ########.fr       */
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

void	print_helper(void)
{
	ft_printf("\n");
	ft_printf("= = = = = = = = = FDF KEY HELPER = = = = = = = = =\n");
	ft_printf("\n");
	ft_printf("TRANSLATION KEYS:\n");
	ft_printf("	UP -> \'W\'\n");
	ft_printf("	LEFT -> \'A\'\n");
	ft_printf("	DOWN -> \'S\'\n");
	ft_printf("	RIGHT -> \'D\'\n");
	ft_printf("\n");
	ft_printf("ROTATION KEYS:\n");
	ft_printf("	LEFT ROTATION -> \'←\'\n");
	ft_printf("	RIGHT ROTATION -> \'→\'\n");
	ft_printf("\n");
	ft_printf("ZOOM KEYS:\n");
	ft_printf("	ZOOM IN -> \'+\'\n");
	ft_printf("	ZOOM OUT -> \'-\'\n");
	ft_printf("\n");
	ft_printf("PERSPECTIVE KEYS:\n");
	ft_printf("	CAVALIER -> \'C\'\n");
	ft_printf("	ISOMETRIC -> \'I\'\n");
	ft_printf("\n");
}
