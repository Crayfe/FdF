/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <causo-f@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/04/03 20:00:26 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	read_color(char *data)
{
	int		color;
	char	**raw_color;

	if (ft_strchr(data, ','))
	{
		raw_color = ft_split(data, ',');
		color = parse_color(raw_color[1]);
		free_2d_str(raw_color);
	}
	else
		color = 0xFFFFFF;
	return (color);
}

int	parse_color(char *raw_color)
{
	int		color;
	int		i;
	int		j;
	char	*h_base;

	h_base = "0123456789ABCDEF";
	i = 0;
	color = 0;
	if (raw_color[0] == '0' && raw_color[1] == 'x')
		i = 2;
	else
		return (0xFFFFFF);
	while (raw_color[i])
	{
		j = 0;
		while (raw_color[i] != h_base[j] && ft_strchr(h_base, raw_color[i]))
			++j;
		if (j == 16)
			j = 0;
		color = (color * 16) + j;
		++i;
	}
	return (color);
}

void	colors_to_rgb(t_colors colors, t_rgb *rgb0, t_rgb *rgb1)
{
	rgb0->r = colors.color0 >> 16;
	rgb0->g = (colors.color0 >> 8) & 0xFF;
	rgb0->b = colors.color0 & 0xFF;
	rgb1->r = colors.color1 >> 16;
	rgb1->g = (colors.color1 >> 8) & 0xFF;
	rgb1->b = colors.color1 & 0xFF;
}

int	get_gradient_color(t_colors colors, int i)
{
	int		color;
	t_rgb	rgb0;
	t_rgb	rgb1;

	if (colors.color0 == colors.color1)
		return (colors.color0);
	else
	{
		colors_to_rgb(colors, &rgb0, &rgb1);
		color = ((rgb0.r + i * ((rgb1.r - rgb0.r) / colors.step)) << 16)
			+ ((rgb0.g + i * ((rgb1.g - rgb0.g) / colors.step)) << 8)
			+ (rgb0.b + i * ((rgb1.b - rgb0.b) / colors.step));
	}
	return (color);
}
