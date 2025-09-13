/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:09:32 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 17:42:58 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (to_find[0] == '\0')
		return ((char *) str);
	while (str[i] && i < len)
	{
		while (str[i + t] == to_find[t] && str[i + t] && i + t < len)
		{
			t++;
			if (to_find[t] == '\0')
				return ((char *) str + i);
		}
		i++;
		t = 0;
	}
	return (NULL);
}
