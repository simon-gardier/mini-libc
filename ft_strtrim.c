/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:32:40 by sgardier          #+#    #+#             */
/*   Updated: 2023/11/01 09:37:31 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_is_in_str(const char *str, size_t str_len, char c)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (i < str_len)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_first_different(char const *str, size_t str_len,
		char const *set, size_t set_len)
{
	size_t	i;
	size_t	begin;

	if (!str || !set)
		return (0);
	i = 0;
	begin = 0;
	while (i < str_len && ft_is_in_str(set, set_len, str[i]))
	{
		begin++;
		i++;
	}
	return (begin);
}

static size_t	ft_after_last_different(char const *str, size_t str_len,
		char const *set, size_t set_len)
{
	size_t	i;
	size_t	after;

	if (!str)
		return (0);
	i = str_len - 1;
	if (!set)
		return (i);
	after = i + 1;
	while (str[i] && i >= 0 && ft_is_in_str(set, set_len, str[i]))
	{
		after--;
		i--;
	}
	return (after);
}

static char	*ft_fill_trimmed(char const *s1, size_t trimmed_str_len,
		size_t begin)
{
	char	*trimmed_str;
	size_t	i;

	trimmed_str = malloc(sizeof(char) * (trimmed_str_len + 1));
	if (!trimmed_str)
		return (NULL);
	i = 0;
	while (i < trimmed_str_len)
	{
		trimmed_str[i] = s1[begin + i];
		i++;
	}
	trimmed_str[trimmed_str_len] = '\0';
	return (trimmed_str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	after;
	size_t	trimmed_str_len;

	if (!s1 || !set)
		return (NULL);
	if (ft_strlen(s1) == 0 || ft_strlen(set) == 0)
		return (ft_strdup(s1));
	begin = ft_first_different(s1, ft_strlen(s1), set, ft_strlen(set));
	after = ft_after_last_different(s1, ft_strlen(s1), set, ft_strlen(set));
	trimmed_str_len = after - begin;
	if (after == 0)
		trimmed_str_len = 0;
	return (ft_fill_trimmed(s1, trimmed_str_len, begin));
}
