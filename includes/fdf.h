/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/08 15:41:53 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERROR 1
# define VALID 0
# define END_INT -1
# define WIDTH 1440
# define HEIGHT 800
/* Colors */
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

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
	int		bpp;
	int		line_len;
	int		endian;
}	t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	t_data	image;
	t_point	**map;
	int		rows;
	int		cols;
}	t_mlx;

/* Library */
# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <string.h>
# include "../libft/inc/libft.h"

/*######## SOURCES ########*/
/* Map Parsing */
int		save_map_figures(t_mlx *var, char *map_file);
int		count_columns(char *filename);
void	free_split(char **split);
void	collect_xyz_data(t_mlx *var, char *filename, int columns);

/* Drawing utils */
void	start_drawing(t_mlx *var, t_point start, t_point end);
t_point	get_point(int x, int y);

/* print; to be removed... */
void	print_saved_figures(int *map, int len);

/* error management */
int	free_line(char *line, int ret);
int	fail_open_file(int error);

#endif
