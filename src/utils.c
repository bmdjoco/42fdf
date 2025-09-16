/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:44:09 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 05:32:44 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	free_point(t_point **point)
{
	int	i;

	if (!point)
		return ;
	i = 0;
	while (point[i])
	{
		free(point[i]);
		i++;
	}
	free(point);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

void	free_app(t_app *app)
{
	if (!app)
		return ;
	if (app->map)
	{
		if (app->map->point)
			free_point(app->map->point);
		free(app->map);
	}
	if (app->mlx)
	{
		if (app->win)
			mlx_destroy_window(app->mlx, app->win);
		mlx_destroy_display(app->mlx);
		free(app->mlx);
	}
	free(app);
}
