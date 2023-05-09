/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:58:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/09 16:54:07 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	std_out_err(char *map_file)
{
	ft_putstr_fd("Enter a valid map <map_name>.fdf\n\n", 2);
	perror(map_file);
}

int	fail_open_file(int error)
{
	perror("Error");
	ft_putstr_fd("Failed to open file\n", 2);
	return (error);
}

int	free_line(char *line, int error)
{
	free(line);
	return (error);
}
