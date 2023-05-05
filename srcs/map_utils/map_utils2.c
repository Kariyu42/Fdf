/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 18:46:16 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/05 21:16:00 by kquetat-         ###   ########.fr       */
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
	ft_printf("len columns = %d\n", len);
	return (len);
}

static void 

void	collect_xyz_data(t_mlx *var, char *filename, int columns)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit(EXIT_FAILURE);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		var->map[i] = malloc(sizeof(t_point) * columns);
		if (!var->map[i])
			exit(EXIT_FAILURE);
		parse_line(tmp, var->map[i]);
		i++;
	}
	close (fd);
}
