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

#define WIDTH	400
#define	HEIGHT	400

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;
	
	if (argc == 1)
		fd = open("model_files/pyramide.fdf", 0);
	else if (argc == 2)
		fd = open(argv[1], 0);
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


	/*
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);
	mlx_window = mlx_new_window(mlx_ptr, HEIGHT, WIDTH, "Test window");
	if (!mlx_window)
	{
		mlx_destroy_display(mlx_ptr);
		free(mlx_ptr);
		return (1);
	}

	mlx_loop(mlx_ptr);
	mlx_destroy_window(mlx_ptr, mlx_window);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
*/
	(void) argc;
	(void) argv;
	return (0);
}
