/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/11 18:47:38 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_window(int keycode, t_mlx *v)
{
	if (keycode == 53)
	{
		mlx_destroy_window(v->mlx, v->win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

static int	red_cross(t_mlx *v)
{
	mlx_destroy_window(v->mlx, v->win);
	exit(EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char **argv)
{
	t_mlx	v;

	if (argc != 2 || save_map_figures(&v, argv[1]) == ERROR)
		exit(EXIT_FAILURE);
	v.mlx = mlx_init();
	if (v.mlx == NULL)
		exit(EXIT_FAILURE);
	v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "FDF - kquetat-");
	if (v.win == NULL)
		exit(EXIT_FAILURE);
	v.data.img = mlx_new_image(v.mlx, WIDTH, HEIGHT);
	if (v.data.img == NULL)
		exit(EXIT_FAILURE);
	v.data.addr = mlx_get_data_addr(v.data.img, &v.data.bpp, \
		&v.data.line_len, &v.data.endian);
	if (v.data.addr == NULL)
		exit(EXIT_FAILURE);
	start_drawing(&v);
	mlx_key_hook(v.win, &close_window, &v);
	mlx_hook(v.win, 17, 1L << 17, &red_cross, &v);
	mlx_loop(v.mlx);
	return (0);
}
