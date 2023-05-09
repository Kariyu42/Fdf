/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:46:16 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/08 15:38:57 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

int	count_columns(char *filename)
{
	char	**split;
	char	*line;
	int		len;
	int		fd;

	len = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (fail_open_file(ERROR));
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	free(line);
	while (split[len])
		len++;
	fd = close(fd);
	free_split(split);
	return (len);
}

static t_point	*parse_line(char *tmp, int columns, int y_axis)
{
	int		i;
	t_point	*table;
	char	**split;

	i = 0;
	split = ft_split(tmp, ' ');
	table = malloc(sizeof(t_point) * columns + 1);
	if (!table)
		exit(EXIT_FAILURE);
	while (split[i] && i < columns)
	{
		table[i].x = i;
		table[i].y = y_axis;
		table[i].z = ft_atoi(split[i]);
		//printf("%d, %d, [%d]\n", table[i].x, table[i].y, table[i].z);
		i++;
	}
	table[i].x = -1;
	free_split(split);
	free(tmp);
	return (table);
}

void	collect_xyz_data(t_mlx *var, char *filename, int columns)
{
	int		i;
	int		fd;
	char	*tmp;

	i = -1;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	var->map = malloc(sizeof(t_point *) * var->rows + 1);
	if (!var->map)
		exit(EXIT_FAILURE);
	while (++i < var->rows)
	{
		tmp = get_next_line(fd);
		var->map[i] = parse_line(tmp, columns, i);
	}
	close (fd);
}
