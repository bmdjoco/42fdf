/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:29:03 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 05:57:09 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/mlx/mlx.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef TYLE_SIZE
#  define TYLE_SIZE 64
# endif

typedef struct s_point {
	float		x;
	float		y;
	float		alt;
}	t_point;

typedef struct s_map {
	int			width;
	int			height;
	float		angle;
	t_point		**point;
}	t_map;

typedef struct s_app
{
	t_map		*map;
	void		*mlx;
	void		*win;
	int			x_size;
	int			y_size;
	int			x_margin;
}	t_app;


int		go_next_line(int fd);
int		check_map(const char *str);
int		map_width(const char *file);
int		map_height(const char *file);
int		get_nb_line(char *file);
int		check_arg(int ac, const char **av);
int		windows_draw(t_app *app);
int		end_app(void *param);

void	draw_line(t_app *app, t_point p1, t_point p2, int color);
void	free_app(t_app *app);
void	free_split(char **split);
void	map_maj_point(t_map *map);
void	free_point(t_point **point);

t_point	**init_point(const char *file, int nb);

#endif
