/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:06:10 by aborda            #+#    #+#             */
/*   Updated: 2025/12/21 10:58:34 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_strndup(char const *src, int n)
{
	char	*dup;
	int		i;

	i = 0;
	dup = malloc(sizeof(char) * (n + 1));
	if (!dup)
		return (0);
	while (i < n)
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

static void	*ft_free_error(char **strings, int j)
{
	while (j > 0)
	{
		free(strings[j - 1]);
		j--;
	}
	free(strings);
	return (NULL);
}

static int	ft_add_word(char **strings, size_t *j, const char *start_ptr,
					size_t len)
{
	strings[*j] = ft_strndup(start_ptr, len);
	if (!strings[*j])
		return (0);
	(*j)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**strings;

	if (s == NULL)
		return (NULL);
	strings = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!strings)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start && !ft_add_word(strings, &j, s + start, i - start))
			return (ft_free_error(strings, j));
	}
	strings[j] = NULL;
	return (strings);
}
