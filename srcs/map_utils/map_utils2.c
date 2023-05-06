/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:46:16 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/06 23:25:01 by kquetat-         ###   ########.fr       */
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
		return (ERROR);
	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (split[len])
		len++;
	fd = close(fd);
	free_split(split);
	printf("count columns function\nlen columns = %d\n", len);
	return (len);
}

static t_point	*parse_line(char *tmp, int columns, int y_axis)
{
	int		i;
	t_point	*table;
	char	**split;

	i = 0;
	split = ft_split(tmp, ' ');
	table = malloc(sizeof(t_point) * columns);
	if (!table)
		exit(EXIT_FAILURE);
	while (split[i] && i < columns)
	{
		table[i].x = i;
		table[i].y = y_axis;
		table[i].z = ft_atoi(split[i]);
		printf("%d, %d, [%d]\n", table[i].x, table[i].y, table[i].z);
		i++;
	}
	free_split(split);
	return (table);
}

void	collect_xyz_data(t_mlx *var, char *filename, int columns)
{
	int		i;
	int		fd;
	char	*tmp;

	i = -1;
	fd = open(filename, O_RDONLY);
	var->map = malloc(sizeof(int *) * var->rows);
	if (!var->map || fd < 0)
		exit(EXIT_FAILURE);
	while (++i < var->rows)
	{
		printf("je rentre %d fois dans la boucle\n", i);
		tmp = get_next_line(fd);
		var->map[i] = malloc(sizeof(t_point) * columns);
		if (!var->map[i])
			exit(EXIT_FAILURE);
		var->map[i] = parse_line(tmp, columns, i);
		free(tmp);
	}
	close (fd);
}
