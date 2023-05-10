/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:28:37 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/09 20:33:41 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void define_start_point(t_mlx *v)
{
	v->map[0][0].x += WIDTH / 2;
	v->map[0][0].y += 20;
	my_mlx_pixel_put(&v->imag, v->map[0][0].x, v->map[0][0].y, WHITE);
	mlx_put_image_to_window(v->mlx, v->win, v->imag.img, 0, 0);
}


void	start_drawing(t_mlx *v)
{
	//t_point	start;
	puts("aaa");
	//start = get_point(0, 0);
	// fonction qui definit le point de depart
	define_start_point(v);
	//put_all_dots();
	mlx_loop(v->mlx);
}
