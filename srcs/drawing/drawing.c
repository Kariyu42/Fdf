/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:28:37 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/08 16:02:46 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

t_point	get_point(int x, int y)
{
	t_point dot;

	dot.x = x;
	dot.y = y;
	return (dot);
}

/* the start_drawing function is a function which has a while loop to draw the map
	point by point using the Bresenham's line algorithm.
	*/
void	start_drawing(t_mlx *v, t_point start, t_point end)
{
	int	i;
	int	x;
	int	y;

	x = start.x * WIDTH;
	i = 0;
	while (i < x)
	{
		y = start.y * HEIGHT;
		while (y < end.y * HEIGHT)
		{
			mlx_pixel_put(v->mlx, v->win, x, y, WHITE);
			y++;
		}
		x++;
	}
}

	/*int i, j;
    for (i = 0; i < var->rows; i++) {
        for (j = 0; j < var->cols; j++) {
            printf("[%d], ", var->map[i][j].x);
            printf("[%d], ", var->map[i][j].y);
            printf("z: %d\n", var->map[i][j].z);
        }
    }*/