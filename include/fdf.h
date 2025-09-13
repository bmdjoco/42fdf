/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:29:03 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/13 17:53:36 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "lib/mlx/mlx.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# ifndef TYLE_SIZE
#  define TYLE_SIZE 64
# endif

typedef struct s_point3d {
	float		x;
	float		y;
	float		z;
}	t_point3d;

typedef struct s_point {
	float		x;
	float		y;
}	t_point;

#endif
