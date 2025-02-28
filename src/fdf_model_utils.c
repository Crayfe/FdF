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
		get_next_line(-1);
		split = ft_split(line, ' ');
		free(line);
		while (split[num_lines])
		{
			if (num_lines > 0)
				free(split[num_lines - 1]);
			num_lines++;
		}
		free(split[num_lines - 1]);
		free(split);
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
		return (num_lines);
	}
	return (-1);
}

int	**load_model(char *model_file)
{
	char	*line;
	int		fd;
	int		**fdf_model;
	int		num_rows;
	int		num_cols;

	num_cols = get_num_cols(model_file);
	num_rows = get_num_rows(model_file);
	ft_printf("NUM ROWS: %i NUM_COLS %i\n", num_rows, num_cols);
	fdf_model = (int **)malloc(sizeof(int) * num_cols * num_rows);
	fd = open(model_file, 0);
	if (fd > 0)
	{
		line = get_next_line(fd);
		while (line)
		{
			ft_printf("%s", line);
			free(line);
			line = get_next_line(fd);
		}
		close(fd);
	}
	return (fdf_model);
}

void	free_model(t_model	*m)
{
	int	**array_model;
	int	i;

	i = 0;
	array_model = m->model;
}
