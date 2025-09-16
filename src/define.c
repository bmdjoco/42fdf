/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 02:00:15 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 06:23:05 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	deg_to_rad(float degrees)
{
	return (degrees * 3.14159265359 / 180.0);
}

static void	apply_isometric_projection(t_point *point, int j, int i, float angle_rad)
{
	float	x_3d;
	float	y_3d;
	float	z_3d;

	x_3d = (float)j;
	y_3d = (float)i;
	z_3d = point->alt;
	point->x = (x_3d - y_3d) * cos(angle_rad);
	point->y = (x_3d + y_3d) * sin(angle_rad) - z_3d;
}

void	map_maj_point(t_map *map)
{
	int		i;
	int		j;
	float	angle_rad;

	angle_rad = deg_to_rad(map->angle);
	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			apply_isometric_projection(&map->point[i][j], j, i, angle_rad);
			j++;
		}
		i++;
	}
}
