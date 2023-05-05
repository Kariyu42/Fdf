/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:31:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/05 19:55:37 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	print_saved_figures(int *map, int len)
{
	int	i;
	
	i = 0;
	while (i < len)
	{
		ft_printf("%d ", map[i]);
		i++;
	}
	ft_printf("\n");
}
/* function at the top must be removed before push */

static int	check_coordinates(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isascii(number[i]))
			return (ERROR);
		i++;
	}
	return (VALID);
}

static int	line_coordinates(t_mlx *var, char *line)
{
	int		i;
	char	**map_part;

	i = 0;
	map_part = ft_split(line, ' ');
	while (map_part[i])
	{
		if (check_coordinates(map_part[i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (VALID);
}

static int	check_map(int fd, t_mlx *var)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_coordinates(var, line) == ERROR)
			return (ERROR);
		var->rows += 1;
	}
	return (VALID);
}

static int	check_invalid_map(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	i++;
	if (ft_strncmp(file + i, "fdf", 3) != 0)
		return (ERROR);
	return (0);
}

int	save_map_figures(t_mlx *var, char *map_file)
{
	int	fd;
	int	col_len;

	if (check_invalid_map(map_file) == ERROR)
		return (ERROR);
	fd = open(map_file, O_RDONLY);
	if (fd < 0 || check_map(fd, var) == ERROR)
		return (ERROR);
	fd = close(fd);
	col_len = count_columns(map_file);
	if (col_len == ERROR)
		return (ERROR);
	collect_xyz_data(var, map_file, col_len);
}
