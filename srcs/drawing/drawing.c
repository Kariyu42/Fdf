/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 10:28:37 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/14 20:31:50 by kquetat-         ###   ########.fr       */
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_len + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	center_shape(t_mlx **v, int mid_x, int mid_y)
{
	int	i;
	int	j;
	int	distance_x;
	int	distance_y;

	distance_x = WIDTH / 2 - (*v)->map[mid_x][mid_y].x; // this is the distance between the center of the window and the center of the shape
	distance_y = HEIGHT / 2 - (*v)->map[mid_x][mid_y].y;
	i = 0;
	puts("center_shape");
	while (i < (*v)->info.num_px)
	{
		j = 0;
		while (j < (*v)->info.num_py)
		{
			(*v)->map[i][j].x += distance_x; // we add the distance to each point of the shape
			(*v)->map[i][j].y += distance_y;
			j++;
		}
		i++;
	}
}

static void	add_scale(int scale, t_mlx **v)
{
	int	i;
	int	j;

	i = 0;
	puts("add_scale");
	printf("(*v)->info.num_px = %d\n", (*v)->info.num_px);
	while (i < (*v)->info.num_px)
	{
		printf("i = %d\n", i);
		j = 0;
		while (j < (*v)->info.num_py)
		{
			printf("x = %d, y = %d\n", (*v)->map[i][j].x, (*v)->map[i][j].y);
			(*v)->map[i][j].x *= scale;
			(*v)->map[i][j].y *= scale;
			j++;
		}
		i++;
	}
	center_shape(&(*v), (*v)->info.num_px / 2, (*v)->info.num_py / 2);
}

static void	place_dots(t_mlx **v)
{
	int	x;
	int	y;

	x = 0;
	puts("place_dots");
	while (x < (*v)->info.num_px)
	{
		y = 0;
		while (y < (*v)->info.num_py)
		{
			my_mlx_pixel_put(&(*v)->data, (*v)->map[x][y].x, \
				(*v)->map[x][y].y, WHITE);
			//printf("x = %d, y = %d\n", (*v)->map[x][y].x, (*v)->map[x][y].y);
			y++;
		}
		x++;
	}
}
// this function uses bresenham's line algorithm to draw lines between each point of the shape
// for each point we draw the vertical and horizontal lines
void	draw_lines(t_mlx **v)
{
	int	i;
	int	j;

	i = 0;
	puts("draw_lines");
	while (i < (*v)->info.num_px)
	{
		j = 0;
		while (j < (*v)->info.num_py)
		{
			if (j + 1 < (*v)->info.num_py)
				ft_bresenham((*v)->map[i][j], (*v)->map[i][j + 1], &(*v)->data);
			if (i + 1 < (*v)->info.num_px)
				ft_bresenham((*v)->map[i][j], (*v)->map[i + 1][j], &(*v)->data);
			j++;
		}
		//draw vertical line for each point
		if (i + 1 < (*v)->info.num_px)
			ft_bresenham((*v)->map[i][j - 1], (*v)->map[i + 1][j - 1], &(*v)->data);
		i++;
	}
	mlx_put_image_to_window((*v)->mlx, (*v)->win, (*v)->data.img, 0, 0);
}


void	start_drawing(t_mlx *v)
{
	printf("start_drawing\n");
	printf("(*v)->info.num_px = %d\n", v->info.num_px);
	printf("(*v)->info.num_py = %d\n", v->info.num_py);
	if (v->info.num_px >= v->info.num_py)
		v->info.scale = WIDTH / 2 / v->info.num_px;
	else
		v->info.scale = HEIGHT / 2 / v->info.num_py;
	add_scale(v->info.scale, &v);
	place_dots(&v);
	draw_lines(&v);
}
