/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:45:00 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 05:57:07 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void	draw_line_low(t_app *app, t_point p1, t_point p2, int color)
{
	int	dx;
	int	dy;
	int	yi;
	int	d;
	int	y;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	yi = 1;
	if (dy < 0)
	{
		yi = -1;
		dy = -dy;
	}
	d = (2 * dy) - dx;
	y = (int)p1.y;
	while ((int)p1.x <= (int)p2.x)
	{
		mlx_pixel_put(app->mlx, app->win, (int)p1.x, y, color);
		if (d > 0)
		{
			y = y + yi;
			d = d + (2 * (dy - dx));
		}
		else
			d = d + 2 * dy;
		p1.x++;
	}
}

static void	draw_line_high(t_app *app, t_point p1, t_point p2, int color)
{
	int	dx;
	int	dy;
	int	xi;
	int	d;
	int	x;

	dx = (int)p2.x - (int)p1.x;
	dy = (int)p2.y - (int)p1.y;
	xi = 1;
	if (dx < 0)
		xi = -1;
	if (dx < 0)
		dx = -dx;
	d = (2 * dx) - dy;
	x = (int)p1.x;
	while ((int)p1.y <= (int)p2.y)
	{
		mlx_pixel_put(app->mlx, app->win, x, (int)p1.y, color);
		if (d > 0)
			x = x + xi;
		if (d > 0)
			d = d + (2 * (dx - dy));
		else
			d = d + 2 * dx;
		p1.y++;
	}
}

void	draw_line(t_app *app, t_point p1, t_point p2, int color)
{
	if (abs((int)p2.y - (int)p1.y) < abs((int)p2.x - (int)p1.x))
	{
		if (p1.x > p2.x)
			draw_line_low(app, p2, p1, color);
		else
			draw_line_low(app, p1, p2, color);
	}
	else
	{
		if (p1.y > p2.y)
			draw_line_high(app, p2, p1, color);
		else
			draw_line_high(app, p1, p2, color);
	}
}
