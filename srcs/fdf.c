/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    fdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:21:41 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/26 12:26:58 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*static void	ft_parsing(int argc, char **argv)
{
	
}*/

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;

	if (argc != 2)
		return (0);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "FDF");
	//ft_parsing(argc, argv);
	return (0);
}
