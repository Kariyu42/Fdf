/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/05 15:49:01 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_struct(t_mlx *var)
{
	var->rows = 0;
	var->image->addr = NULL;
	var->image->bits_per_pixel = 0;
	var->image->line_length = 0;
	var->image->endian = 0;
}

int	main(int argc, char **argv)
{
	t_mlx	var;

	init_struct(&var);
	if (argc != 2 || save_map_figures(&var, argv[1]) == ERROR)
		exit(EXIT_FAILURE);
	var.mlx = mlx_init();
	if (var.mlx == NULL)
		exit(EXIT_FAILURE);
	var.win = mlx_new_window(var.mlx, WIDTH, HEIGHT, "FDF");
	if (var.win == NULL)
		exit(EXIT_FAILURE);
	var.image->img = mlx_new_image(var.mlx, WIDTH, HEIGHT);
	draw_map(&var);
	mlx_loop(var.mlx);
	return (0);
}
