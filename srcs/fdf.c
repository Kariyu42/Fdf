/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/10 12:57:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_mlx	v;

	if (argc != 2 || save_map_figures(&v, argv[1]) == ERROR)
		exit(EXIT_FAILURE);
	if ((v.mlx = mlx_init()) != NULL)
	{
		puts("mlx_init success");
		v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "FDF - kquetat-");
		if (v.win == NULL)
			exit(EXIT_FAILURE);
		if ((v.data.img = mlx_new_image(v.mlx, WIDTH, HEIGHT)) == NULL)
			exit(EXIT_FAILURE);
		v.data.addr = mlx_get_data_addr(v.data.img, &v.data.bpp, \
			&v.data.line_len, &v.data.endian);
		if (v.data.addr == NULL)
			exit(EXIT_FAILURE);
		start_drawing(&v);
	}
	return (0);
}
