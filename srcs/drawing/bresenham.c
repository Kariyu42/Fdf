/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:57:24 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/14 14:38:03 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
// function draws pixels between two points	til t_point end
void	ft_bresenham(t_point start, t_point end, t_data *data)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	e;

	puts("ft_bresenham");
	dx = end.x - start.x;
	dy = end.y - start.y;
	e = 2 * dy - dx;
	x = start.x;
	y = start.y;
	while (x < end.x)
	{
		my_mlx_pixel_put(data, x, y, WHITE);
		if (e > 0)
		{
			y++;
			e += 2 * dy - 2 * dx;
		}
		else
			e += 2 * dy;
		x++;
	}
}
