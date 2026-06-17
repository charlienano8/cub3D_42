/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborda <aborda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:52:09 by aborda            #+#    #+#             */
/*   Updated: 2025/12/21 10:06:30 by aborda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_calc_len(int start, int end)
{
	size_t	len;

	if (end >= start)
		len = end - start + 1;
	else
		len = 0;
	return (len);
}

static char	*ft_malloc_and_copy(char const *s1, size_t start_set,
								size_t end_set)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (ft_calc_len(start_set, end_set) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (start_set <= end_set)
	{
		str[i++] = s1[start_set];
		start_set++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start_set;
	size_t	end_set;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start_set = 0;
	if (s1[0] == '\0')
		return (ft_strdup(""));
	else
		end_set = ft_strlen(s1) - 1;
	while (s1[start_set] && ft_check_set(s1[start_set], set) == 1)
		start_set++;
	while (end_set > start_set && ft_check_set(s1[end_set], set) == 1)
		end_set--;
	str = ft_malloc_and_copy(s1, start_set, end_set);
	return (str);
}
