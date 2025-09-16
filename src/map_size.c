/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 16:52:30 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 02:25:38 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

/**
 * @brief renvoie le nombre de ligne d'un fichier
 *
 * @return renvoie le nombre de ligne ou -1 dans le cas
 * ou l'on arrive pas a acceder au fichier'
 */
int	map_height(const char *file)
{
	int	fd;
	int	nb;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : fd error\n", 2), -1);
	nb = 0;
	while (go_next_line(fd))
		nb++;
	close(fd);
	return (nb);
}

static int	count_numbers_in_line(char *line)
{
	char	**split;
	int		count;
	int		i;
	int		len;

	if (!line)
		return (0);
	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	count = 0;
	while (split[count])
		count++;
	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (count);
}

/**
 * @brief renvoie le nombre de nombres par ligne et vérifie la cohérence
 *
 * @return renvoie le nombre de nombres par ligne ou 0 si les lignes
 * n'ont pas toutes le même nombre de nombres
 */
int	map_width(const char *file)
{
	int		fd;
	char	*line;
	int		first_count;
	int		current_count;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("Error : fd error\n", 2), 0);
	line = get_next_line(fd);
	if (!line)
		return (close(fd), 0);
	first_count = count_numbers_in_line(line);
	free(line);
	while ((line = get_next_line(fd)) != NULL)
	{
		current_count = count_numbers_in_line(line);
		if (current_count != first_count)
		{
			free(line);
			return (close(fd), 0);
		}
		free(line);
	}
	close(fd);
	return (first_count);
}
