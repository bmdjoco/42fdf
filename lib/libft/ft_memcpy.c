/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:36:36 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/02 13:33:45 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmpd;
	char	*tmps;
	size_t	i;

	if (src == NULL && dest == NULL)
		return (dest);
	tmpd = (char *)dest;
	tmps = (char *)src;
	i = 0;
	while (i < n)
	{
		tmpd[i] = tmps[i];
		i++;
	}
	return (dest);
}
/*
#include <stdio.h>
int main(void) {
	char	s[] = "Bye";
	char	d[] = "Hola";
	printf(">| %s\n", d);
	ft_memcpy( d, s, (size_t) (sizeof(char)*3));
	printf("<| %s\n", d);

	return 0;
}
*/
