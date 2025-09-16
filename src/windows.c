/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:05:12 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 06:17:50 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	end_app(void *param)
{
	t_app	*app;

	app = (t_app *) param;
	free_app(app);
	exit(0);
}

static void	draw_horizontal_line(t_app *app, int i, int j, int scale)
{
	t_point	p1;
	t_point	p2;
	int		offset_x;
	int		offset_y;

	offset_x = app->x_size / 2 - (app->map->width * scale) / 2;
	offset_y = app->y_size / 2 - (app->map->height * scale) / 2;
	p1.x = app->map->point[i][j].x * scale + offset_x;
	p1.y = app->map->point[i][j].y * scale + offset_y;
	p2.x = app->map->point[i][j + 1].x * scale + offset_x;
	p2.y = app->map->point[i][j + 1].y * scale + offset_y;
	draw_line(app, p1, p2, 0xFFFFFF);
}

static void	draw_vertical_line(t_app *app, int i, int j, int scale)
{
	t_point	p1;
	t_point	p2;
	int		offset_x;
	int		offset_y;

	offset_x = app->x_size / 2 - (app->map->width * scale) / 2;
	offset_y = app->y_size / 2 - (app->map->height * scale) / 2;
	p1.x = app->map->point[i][j].x * scale + offset_x;
	p1.y = app->map->point[i][j].y * scale + offset_y;
	p2.x = app->map->point[i + 1][j].x * scale + offset_x;
	p2.y = app->map->point[i + 1][j].y * scale + offset_y;
	draw_line(app, p1, p2, 0xFFFFFF);
}

static int	calculate_scale(t_app *app)
{
	int	scale;

	scale = (app->x_size * 5) / (app->map->width * 10);
	if (scale < 5)
		scale = 5;
	if (scale > 50)
		scale = 50;
	return (scale);
}

int	windows_draw(t_app *app)
{
	int	i;
	int	j;
	int	scale;

	scale = calculate_scale(app);
	i = 0;
	while (i < app->map->height)
	{
		j = 0;
		while (j < app->map->width)
		{
			if (j < app->map->width - 1)
				draw_horizontal_line(app, i, j, scale);
			if (i < app->map->height - 1)
				draw_vertical_line(app, i, j, scale);
			j++;
		}
		i++;
	}
	return (1);
}
