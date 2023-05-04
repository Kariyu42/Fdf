/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/04 13:16:15 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_struct(t_struct *map_t)
{
	map_t->var->
}

int	main(int argc, char **argv)
{
	t_struct	map_t;

	init_struct(&map_t);
	if (init_inspect(argc, argv, &map_t) == ERROR)
		exit(EXIT_FAILURE);
	save_map_figures(&map_t, argv[1]);
	map_t.mlx = mlx_init();
	if (map_t.mlx == NULL)
		exit(EXIT_FAILURE);
	map_t.win = mlx_new_window(map_t.mlx, WIDTH, HEIGHT, "FDF");
	if (map_t.win == NULL)
		exit(EXIT_FAILURE);
	draw_map(&map_t);
	mlx_loop(map_t.mlx);
	return (0);
}
