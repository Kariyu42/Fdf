/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:56:30 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/14 14:15:12 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// add -45 degree rotation on y-axis and 45 degree rotation on x-axis
void	apply_rotation(t_mlx **v)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*v)->info.num_px)
	{
		j = 0;
		while (j < (*v)->info.num_py)
		{
			(*v)->map[i][j].x = (*v)->map[i][j].x * cos(40) + (*v)->map[i][j].z * sin(40);
			(*v)->map[i][j].y = (*v)->map[i][j].y * cos(45 * M_PI / 180) - (*v)->map[i][j].z * sin(45 * M_PI / 180);
			j++;
		}
		i++;
	}
}
