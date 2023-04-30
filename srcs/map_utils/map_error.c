/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:13:53 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/30 14:17:31 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static int	check_coordinates(char *number)
{
	int	i;

	i = 0;
	while (number[i])
	{
		if (!ft_isdigit(number[i]) && number[i] != '\n')
			return (ERROR);
		i++;
	}
	return (VALID);
}

static int	line_coordinates(t_struct *map_t, char *line)
{
	int		i;
	char	**map_part;

	i = 0;
	map_part = ft_split(line, ' ');
	while (map_part[i])
	{
		//ft_printf("map_part =\n%s\n", map_part[i]);
		if (check_coordinates(map_part[i]) == ERROR)
			return (ERROR);
		i++;
	}
	map_t->base_len++;
	return (VALID);
}

static int	check_map(int fd, t_struct *map_t)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		//ft_printf("line =\n %s\n", line);
		if (line == NULL)
			break ;
		if (line_coordinates(map_t, line) == ERROR)
			return (ERROR);
	}
	return (VALID);
}

static int	check_error_map(char *file)
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

int	init_inspect(int argc, char **argv, t_struct *map_t)
{
	int	fd;

	if (argc != 2 || check_error_map(argv[1]) == ERROR)
		return (ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || check_map(fd, map_t) == ERROR)
	{
		//puts("hello");
		fd = close(fd);
		return (ERROR);
	}
	fd = close(fd);
	return (VALID);
}
