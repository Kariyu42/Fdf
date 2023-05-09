/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/09 16:19:57 by kquetat-         ###   ########.fr       */
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
		v.win = mlx_new_window(v.mlx, WIDTH, HEIGHT, "FDF - kquetat-");
		if (v.win == NULL)
			exit(EXIT_FAILURE);
		if ((v.imag.img = mlx_new_image(v.mlx, WIDTH, HEIGHT)) == NULL)
			exit(EXIT_FAILURE);
		v.imag.addr = mlx_get_data_addr(v.imag.img, &v.imag.bpp, \
			&v.imag.line_len, &v.imag.endian);
		if (v.imag.addr == NULL)
			exit(EXIT_FAILURE);
		start_drawing(&v);
	}
	return (0);
}
