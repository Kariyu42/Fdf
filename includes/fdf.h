/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/04 13:11:09 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERROR 1
# define VALID 0
# define END_INT -1
# define WIDTH 1920
# define HEIGHT 1080

/* Struct */
typedef struct s_point
{
	int	x; // x-axis data
	int	y; // y-axis data
	int	z; // altitude data which we parse from the map
}	t_point;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_struct
{
	void	*mlx;
	void	*win;
	t_data	*var;
	t_point	**map;
}	t_struct;

/* Library */
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/inc/libft.h"

/*######## SOURCES ########*/
/* Map Errors */
int	init_inspect(int argc, char **argv, t_struct *map_t);

/* Map Parsing */
void	save_map_figures(t_struct *map_t, char *map_file);

/* Drawing utils */
void	draw_map(t_struct *map_t);
/* print; to be removed... */
void	print_saved_figures(int *map, int len);

#endif
