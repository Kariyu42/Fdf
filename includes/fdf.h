/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:55:49 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/30 13:45:04 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ERROR -1
# define VALID 0

/* Struct */
typedef struct s_struct
{
	int	**map;
	int	base_len;
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

/* print; to be removed... */
void	print_saved_figures(int *map, int len);

#endif
