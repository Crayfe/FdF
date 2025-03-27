/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crayfe <crayfe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:11:57 by cayuso-f          #+#    #+#             */
/*   Updated: 2025/03/25 17:19:42 by crayfe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_round(float n)
{
	int		floor_n;
	float	fraction;

	floor_n = (int)n;
	fraction = n - floor_n;
	if (fraction < 0.5)
		return (floor_n);
	return (floor_n + 1);
}
