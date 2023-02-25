/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkarib <gkarib@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:04:40 by gkarib            #+#    #+#             */
/*   Updated: 2023/02/25 01:41:58 by gkarib           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			words++;
		}
	}
	return (words);
}

static char	**free_handle(int j, char	**split)
{
	while (j >= 0)
	{
		free(split[j]);
		j--;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	split = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!split)
		return (NULL);
	while (j < ft_count_words(s, c))
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[j++] = ft_substr(s, start, i - start);
		if (!split[j - 1])
			return (free_handle(j, split));
	}
	split[j] = NULL;
	return (split);
}

// int main()
// {
// 	char **ret = ft_split("heki fffff fff", ' ');
// 	int i = 0;
// 	while (ret[i])
// 	{
// 		printf("%s\n", ret[i]);
// 		i++;
// 	}
// }