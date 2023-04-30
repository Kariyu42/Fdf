/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/30 14:33:08 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_struct(t_struct *map_t)
{
	map_t->map = 0;
	map_t->base_len = 0;
}

int	main(int argc, char **argv)
{
	//void		*mlx;
	t_struct	map_t;
	//void		*mlx_win;

	init_struct(&map_t);
	if (init_inspect(argc, argv, &map_t) == ERROR)
	{
		perror("Invalid input");
		return (1);
	}
	save_map_figures(&map_t, argv[1]);
	
	//mlx = mlx_init();
	//mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	return (0);
}
