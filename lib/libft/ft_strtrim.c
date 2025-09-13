/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 12:05:28 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/05 16:25:23 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isin(char const *res, char c)
{
	int	i;

	i = 0;
	while (res[i])
	{
		if (res[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*create_str(const char *s1, size_t start, size_t len)
{
	char	*res;
	size_t	i;

	if (len <= 0 || start >= ft_strlen(s1))
		return (ft_strdup(""));
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < len)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (isin(set, s1[i]))
		i++;
	while (isin(set, s1[j]))
		j--;
	return (create_str(s1, i, j - (i - 1)));
}
/*
#include <stdio.h>
int main(void)
{
	char *s1 = ".,@Te.St.,!";
	char *set = ".,!@/";
	char *res;

	res = ft_strtrim(s1, set);
	if (res == NULL)
		return (1);
	printf("String | %s\n", s1);
	printf("Set | %s\n", set);
	printf("String Trim | %s\n", res);
	free(res);
	return 0;
}
*/
