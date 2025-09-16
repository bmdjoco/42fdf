/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:28:52 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 06:20:40 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_map	*init_map(const char *file)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (ft_putstr_fd("Error : Malloc fail\n", 2), NULL);
	map->height = map_height(file);
	map->width = map_width(file);
	if (map->height == -1 || !map->width || !check_map(file))
		return (ft_putstr_fd("Error : Map not valid\n", 2), NULL);
	map->angle = 30;
	map->point = init_point(file, map->height);
	if (!map->point)
		return (free(map), NULL);
	return (map);
}

static int	handle_mlx_init_error(t_app *app)
{
	free_point(app->map->point);
	free(app->map);
	free(app);
	ft_putstr_fd("Error : MLX Init fail\n", 2);
	return (0);
}

static int	handle_screen_size_error(t_app *app)
{
	free_point(app->map->point);
	free(app->map);
	free(app);
	ft_putstr_fd("Error : MLX Get Screen Size fail\n", 2);
	return (0);
}

static int	handle_window_error(t_app *app)
{
	mlx_destroy_display(app->mlx);
	free(app->mlx);
	free_point(app->map->point);
	free(app->map);
	free(app);
	ft_putstr_fd("Error : MLX windows fail\n", 2);
	return (0);
}

int	init_mlx(t_app *app)
{
	int	x;
	int	y;

	app->mlx = mlx_init();
	if (!app->mlx)
		return (handle_mlx_init_error(app));
	x = 0;
	y = 0;
	if (mlx_get_screen_size(app->mlx, &x, &y) == -1)
		return (handle_screen_size_error(app));
	app->x_margin = (int)(x * 0.3);
	app->x_size = (int)(x * 0.7);
	app->y_size = y;
	app->win = mlx_new_window(app->mlx, x, y, "FDF (Fil De Fer)");
	if (!app->win)
		return (handle_window_error(app));
	return (1);
}

int	main(int ac, char const **av)
{
	t_app	*app;
	t_map	*map;

	if (!check_arg(ac, av))
		return (1);
	map = init_map(av[1]);
	map_maj_point(map);
	app = ft_calloc(1, sizeof(t_app));
	if (!app)
		return (free_point(map->point), free(map),
			ft_putstr_fd("Error : Malloc fail\n", 2), 1);
	app->map = map;
	if (!init_mlx(app))
		return (1);
	if (!windows_draw(app))
		return (free_app(app), 1);
	mlx_hook(app->win, 17, 0L, end_app, app);
	mlx_loop(app->mlx);
	return (0);
}
