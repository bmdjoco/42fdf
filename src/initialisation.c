/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 00:15:32 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 02:11:55 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int	count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

static int	fill_line_points(t_point *line, char **split, int row)
{
	int	j;

	j = 0;
	while (split[j])
	{
		line[j].x = (float)j;
		line[j].y = (float)row;
		line[j].alt = (float)ft_atoi(split[j]);
		free(split[j]);
		j++;
	}
	return (1);
}

static int	process_line(t_point **point, char *str, int i)
{
	char	**split;
	int		width;

	split = ft_split(str, ' ');
	if (!split)
		return (0);
	width = count_split(split);
	point[i] = ft_calloc(width + 1, sizeof(t_point));
	if (!point[i])
	{
		free_split(split);
		return (0);
	}
	fill_line_points(point[i], split, i);
	free(split);
	return (1);
}

static int	write_point(t_point **point, int fd, char *str)
{
	int	i;

	i = 0;
	while (str)
	{
		if (!process_line(point, str, i))
			return (free(str), 0);
		free(str);
		str = get_next_line(fd);
		i++;
	}
	return (1);
}

t_point	**init_point(const char *file, int nb)
{
	int		fd;
	char	*str;
	t_point	**point;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : fd error\n", 2), NULL);
	str = get_next_line(fd);
	if (!str)
		return (close(fd), NULL);
	point = ft_calloc((size_t)(nb + 1), sizeof(t_point *));
	if (!point)
		return (free(str), close(fd), NULL);
	if (!write_point(point, fd, str))
		return (free_point(point), free(str), close(fd), NULL);
	close(fd);
	return (point);
}
