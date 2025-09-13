/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bdjoco <bdjoco@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:09:50 by bdjoco            #+#    #+#             */
/*   Updated: 2025/05/07 13:27:07 by bdjoco           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getnbw(const char *s, char sep)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
			words++;
		while (s[i] && !(s[i] == sep))
			i++;
	}
	return (words);
}

static char	*alloc_word(const char *str, char sep)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (str[len] && !(str[len] == sep))
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static void	*free_words(char **words, int j)
{
	while (j)
	{
		j--;
		free(words[j]);
	}
	free(words);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = (char **)malloc(sizeof(char *) * (getnbw(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			res[j] = alloc_word(&s[i], c);
			if (!res[j])
				return (free_words(res, j));
			j++;
		}
		while (s[i] && !(s[i] == c))
			i++;
	}
	res[j] = NULL;
	return (res);
}
/*
int main(void)
{
	char *str = "home/destktop/folder/image.jpg";
	printf("Setence | %s\n\n", str);
	char **res = ft_split(str, '/');
	if (res == NULL)
		return (0);
	int i;
	i = 0;
	while (res[i] != NULL)
	{
		printf("Array %d | %s\n", i, res[i]);
		free(res[i]);
		i++;
	}

	return 0;
}
*/
