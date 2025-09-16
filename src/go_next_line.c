/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_next_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 12:28:38 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/16 02:07:43 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char	*read_to_stash(int fd, char *stash)
{
	char	*buff;
	char	*tmp;
	ssize_t	is_end;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff || !stash)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		is_end = read(fd, buff, BUFFER_SIZE);
		if (is_end < 1)
			break ;
		buff[is_end] = '\0';
		tmp = ft_strjoin(stash, buff);
		if (!tmp)
			return (free(buff), NULL);
		free(stash);
		stash = tmp;
	}
	free(buff);
	return (stash);
}

/**
 * @brief lis un fichier ligne par ligne
 *
 * @return renvoie 1 si le fichier n'est pas fini sinon 0
 */
int	go_next_line(int fd)
{
	static char	*stash;
	char		*n_stash;
	size_t		i;

	if (!stash)
		stash = ft_calloc(1, 1);
	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
		return (free(stash), stash = NULL, 0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	n_stash = ft_strdup(stash + i);
	if (!n_stash)
		return (free(n_stash), 0);
	free(stash);
	stash = n_stash;
	return (1);
}
