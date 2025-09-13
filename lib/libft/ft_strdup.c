/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:04:49 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 12:38:49 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	int		l;
	char	*res;

	l = 0;
	while (src[l])
		l++;
	res = (char *) malloc((l + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strcpy(res, src);
	return (res);
}
/*
int	main(void)
{
	int	i;
	char	*txt;

	txt = ft_strdup("Perdri");
	if (txt == NULL)
		return (0);
	i = 0;
	while (txt[i])
	{
		write(1, &txt[i], 1);
		i++;
	}
	free(txt);
}*/
