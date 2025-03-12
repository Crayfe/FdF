/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cayuso-f <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:44:08 by cayuso-f          #+#    #+#             */
/*   Updated: 2024/11/25 11:39:49 by cayuso-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft/src/libft.h"
#include "../minilibx/mlx.h"
#include "../minilibx/mlx_int.h"
#define WIDTH   400
#define HEIGHT  400

typedef struct s_model_data
{
	int	**model;
	int	**colors;
	int	num_rows;
	int	num_cols;
}	t_model;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_model	*fdf_model;
}	t_mlx_data;

/* fdf_model_utils.c */
int		get_num_cols(char *file);
int		get_num_rows(char *file);
t_model	*load_model(char *model_file);
void	free_model(t_model	*m);
void	print_model(t_model *m);
/* fdf_window_utils.c */
int		handle_keys(int key, t_mlx_data *mlibx);
int		setup_win(t_mlx_data *mlibx);