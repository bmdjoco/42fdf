/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 17:41:13 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 02:17:25 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	check_arg(int ac, const char **av)
{
	if (ac != 2)
		return (ft_putstr_fd("Error : Usage ./fdf <file.fdf>\n", 2), 0);
	else if (ft_strlen(av[1]) < 5 ||
		ft_strncmp(av[1] + (ft_strlen(av[1]) - 4), ".fdf", 4))
		return (ft_putstr_fd("Error : You need a '.fdf' file\n", 2), 0);
	return (1);
}

static int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_line(char *line)
{
	char	**split;
	int		i;
	int		len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	i = 0;
	while (split[i])
	{
		if (!is_valid_number(split[i]))
		{
			while (split[i])
				free(split[i++]);
			return (free(split), 0);
		}
		free(split[i]);
		i++;
	}
	return (free(split), 1);
}

int	check_map(const char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((line = get_next_line(fd)) != NULL)
	{
		if (!check_line(line))
		{
			free(line);
			return (close(fd), 0);
		}
		free(line);
	}
	return (close(fd), 1);
}
