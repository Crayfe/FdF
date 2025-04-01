/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_model_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:49 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "FdF.h"
#include <fcntl.h>

int	get_num_cols(char *file)
{
	int		fd;
	int		num_lines;
	char	*line;
	char	**split;

	fd = open(file, 0);
	if (fd > 0)
	{
		num_lines = 0;
		line = get_next_line(fd);
		split = ft_split(line, ' ');
		free(line);
		get_next_line(-1);
		while (split[num_lines])
			num_lines++;
		free_2d_str(split);
		close(fd);
		return (num_lines);
	}
	return (-1);
}

int	get_num_rows(char *file)
{
	int		fd;
	int		num_lines;
	char	c;

	fd = open(file, 0);
	if (fd > 0)
	{
		num_lines = 1;
		while (read(fd, &c, 1) > 0)
			if (c == '\n')
				++num_lines;
		close(fd);
		return (num_lines - 1);
	}
	return (-1);
}

int	load_color(char *data)
{
	int	color;

	if (ft_strchr(data, ','))
		color = 0xFF0000;
	else
		color = 0xFFFFFF;
	return (color);
}

int	load_new_row(t_model *m, char *line, int row)
{
	char	**split;
	int		i;

	if (!line)
		return (0);
	split = ft_split(line, ' ');
	free(line);
	i = 0;
	while (i <= m->num_cols - 1)
	{
		ft_printf("%s\n", split[i]);
		m->model[row][i] = ft_atoi(split[i]);
		m->colors[row][i] = load_color(split[i]);
		i++;
	}
	free_2d_str(split);
	return (1);
}

t_model	*load_model(char *model_file)
{
	int		fd;
	int		i;
	t_model	*fdf_model;

	fdf_model = malloc(sizeof(t_model));
	fdf_model->num_cols = get_num_cols(model_file);
	fdf_model->num_rows = get_num_rows(model_file);
	fdf_model->model = malloc(sizeof(int *) * fdf_model->num_rows);
	fdf_model->colors = malloc(sizeof(int *) * fdf_model->num_rows);
	i = -1;
	while (i++ < fdf_model->num_rows - 1)
	{
		fdf_model->model[i] = malloc(sizeof(int) * fdf_model->num_cols);
		fdf_model->colors[i] = malloc(sizeof(int) * fdf_model->num_cols);
	}
	fd = open(model_file, 0);
	if (fd > 0)
	{
		i = 0;
		while (load_new_row(fdf_model, get_next_line(fd), i))
			i++;
		close(fd);
	}
	return (fdf_model);
}

void	free_model(t_model	*m)
{
	int	i;

	i = -1;
	while (++i < m->num_rows)
	{
		free((int *)m->model[i]);
		free((int *)m->colors[i]);
	}
	free(m->model);
	free(m->colors);
	free(m);
}

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
			ft_printf("%x ", fdf->colors[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
