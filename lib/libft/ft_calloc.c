/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:50:08 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 17:04:06 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t			i;
	unsigned char	*res;

	res = malloc(count * size);
	if (!res)
		return (NULL);
	i = 0;
	while (i < size * count)
	{
		res[i] = 0;
		i++;
	}
	return (res);
}
