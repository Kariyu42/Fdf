/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 14:58:03 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/08 15:04:22 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

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
