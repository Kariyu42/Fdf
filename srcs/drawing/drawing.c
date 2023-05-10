/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:28:37 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/10 14:06:53 by kquetat-         ###   ########.fr       */
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

/*static void define_start_point(t_mlx *v)
{
	v->map[0][0].x += WIDTH / 2;
	v->map[0][0].y += 20;
	my_mlx_pixel_put(&v->imag, v->map[0][0].x, v->map[0][0].y, WHITE);
	mlx_put_image_to_window(v->mlx, v->win, v->imag.img, 0, 0);
}*/

static void	add_scale(int scale, t_mlx **v)
{
	int	i;
	int	j;

	i = 0;
	while (i < (*v)->info.num_px)
	{
		j = 0;
		while (j < (*v)->info.num_py)
		{
			(*v)->map[i][j].x *= scale;
			(*v)->map[i][j].y *= scale;
			j++;
		}
		i++;
	}
}

static void	place_dots(t_mlx **v)
{
	int	x;
	int	y;

	x = 0;
	while (x < (*v)->info.num_px)
	{
		y = 0;
		while (y < (*v)->info.num_py)
		{
			my_mlx_pixel_put(&(*v)->data, (*v)->map[x][y].x, \
				(*v)->map[x][y].y, WHITE);
			printf("x = %d, y = %d\n", (*v)->map[x][y].x, (*v)->map[x][y].y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window((*v)->mlx, (*v)->win, (*v)->data.img, 0, 0);
	mlx_loop((*v)->mlx);
}

void	start_drawing(t_mlx *v)
{
	if (v->info.num_px >= v->info.num_py)
		v->info.scale = WIDTH / 2 / v->info.num_px;
	else
		v->info.scale = HEIGHT / 2 / v->info.num_py;
	add_scale(v->info.scale, &v); // add all x,y scale and correct positioning for iso projection
	place_dots(&v);
}
