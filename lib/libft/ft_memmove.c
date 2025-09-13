/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 14:27:40 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 17:30:03 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*tmps;
	char	*tmpd;
	size_t	i;

	i = 0;
	if (!dst && !src)
		return (NULL);
	tmps = (char *) src;
	tmpd = (char *) dst;
	if (tmpd > tmps)
		while (len-- > 0)
			tmpd[len] = tmps[len];
	else
	{
		while (i < len)
		{
			tmpd[i] = tmps[i];
			i++;
		}
	}
	return (dst);
}

/*
#include <stdio.h>
#include <string.h>
int main(void) {
	char	s[] = "Bye";
	char	d[] = "Hola";
	printf(">| %s\n", d);
	ft_memmov( d, s, (size_t) (sizeof(char)*3));
	printf("<| %s\n", d);
	memmov( d, s, (size_t) (sizeof(char)*3));
	printf(">| %s\n", d);

	return 0;
}
*/
