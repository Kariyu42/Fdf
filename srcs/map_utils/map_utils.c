/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:31:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/12 21:26:10 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

static int	line_coordinates(char *line)
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
	free_split(map_part);
	return (VALID);
}

static int	check_map(char *map, t_mlx *var)
{
	int		fd;
	char	*line;

	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (fail_open_file(ERROR));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line_coordinates(line) == ERROR)
			return (free_line(line, ERROR));
		free(line);
		var->info.num_px += 1;
	}
	fd = close(fd);
	printf("num_px = %d\n", var->info.num_px);
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
	if (check_invalid_map(map_file) == ERROR)
		return (std_out_err(map_file), ERROR);
	init_struct(var);
	if (check_map(map_file, var) == ERROR)
		return (ERROR);
	if ((var->info.num_py = count_columns(map_file)) == ERROR)
		return (ERROR);
	collect_xyz_data(var, map_file, var->info.num_py);
	return (VALID);
}
