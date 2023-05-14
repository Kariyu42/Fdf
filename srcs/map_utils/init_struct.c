/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kquetat- <kquetat-@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 21:22:15 by kquetat-          #+#    #+#             */
/*   Updated: 2023/05/12 21:23:23 by kquetat-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_struct(t_mlx *v)
{
	v->info.num_px = 0;
	v->info.num_py = 0;
	v->info.scale = 0;
}
