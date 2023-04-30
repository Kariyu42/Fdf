/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 16:31:56 by kquetat-          #+#    #+#             */
/*   Updated: 2023/04/30 14:31:02 by kquetat-         ###   ########.fr       */
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

static int	length_data(char **tab)
{
	int	len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

static int	*collect_figures(char *line)
{
	int		i;
	int		*tab;
	char	**tmp;

	i = 0;
	tmp = ft_split(line, ' ');
	tab = malloc(sizeof(int) * length_data(tmp));
	while (tmp[i])
	{
		tab[i] = ft_atoi(tmp[i]);
		i++;
	}
	//print_saved_figures(tab, length_data(tmp));
	free(tmp);
	return (tab);
}

void	save_map_figures(t_struct *map_t, char *map_file)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	map_t->map = malloc(sizeof(int) * map_t->base_len);
	if (!map_t->map)
		exit(EXIT_FAILURE);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		perror("Invalid fd: Tried to open in save_map_figures();\n");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_t->map[i] = collect_figures(line);
		i++;
	}
}
