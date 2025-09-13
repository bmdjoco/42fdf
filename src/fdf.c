/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 17:28:52 by bdjoco            #+#    #+#             */
/*   Updated: 2025/09/13 17:58:23 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/fdf.h"

t_point3d	**point_file(int fd)
{

}

int main(int ac, const char **av)
{
	int			fd;
	t_point3d	**tmp;

	if (ac != 2)
		return (ft_putstr_fd("Error : usage ./fdf <file.fdf>\n", 2), 1);
	fd = open(av[1], O_RDONLY);
	if (fd = -1)
		return (ft_putstr_fd("Error : file cannot be open\n", 2), 1);
	tmp = point_file(fd);
	close(fd);
	
	return 0;
}
