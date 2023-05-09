/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/08 15:41:13 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_struct(t_mlx *var)
{
	var->cols = 0;
	var->mlx = NULL;
	var->win = NULL;
	var->rows = 0;
	var->image.addr = NULL;
	var->image.bpp = 0;
	var->image.line_len = 0;
	var->image.endian = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	v;

	init_struct(&v);
	if (argc != 2 || save_map_figures(&v, argv[1]) == ERROR)
		exit(EXIT_FAILURE);
	if ((v.mlx = mlx_init()) == NULL)
		exit(EXIT_FAILURE);
	v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "FDF");
	if (v.win == NULL)
		exit(EXIT_FAILURE);
	if ((v.image.img = mlx_new_image(v.mlx, WIDTH, HEIGHT)) == NULL)
		exit(EXIT_FAILURE);
	v.image.addr = mlx_get_data_addr(v.image.img,
		&v.image.bpp, &v.image.line_len, &v.image.endian);
	if (v.image.addr == NULL)
		exit(EXIT_FAILURE);
	/* the start_drawing function is a function which has a while loop to draw the map
	point by point using the Bresenham's line algorithm.
	*/
	start_drawing(&v, get_point(0, 0), get_point(v.rows, v.cols));
	mlx_loop(v.mlx);
	return (0);
}
