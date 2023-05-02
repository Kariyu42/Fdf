/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/02 14:17:27 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_struct(t_struct *map_t)
{
	map_t->map = 0;
	map_t->base_len = 0;
	map_t->width = 1920;
	map_t->height = 1080;
}

int	main(int argc, char **argv)
{
	t_struct	map_t;

	init_struct(&map_t);
	if (init_inspect(argc, argv, &map_t) == ERROR)
		exit(EXIT_FAILURE);
	save_map_figures(&map_t, argv[1]);
	map_t.mlx_id = mlx_init();
	if (map_t.mlx_id == NULL)
		exit(EXIT_FAILURE);
	map_t.mlx_win = mlx_new_window(map_t.mlx_id, map_t.width, map_t.height, "FDF");
	if (map_t.mlx_win == NULL)
		exit(EXIT_FAILURE);
	int	i = 0;
	int	y = 0;
	while (i < 100)
	{
		mlx_pixel_put(map_t.mlx_id, map_t.mlx_win, i, y, 44569);
		i++;
		y++;
	}
	mlx_loop(map_t.mlx_id);
	return (0);
}
