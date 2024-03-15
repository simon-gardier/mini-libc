/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:56:43 by setun             #+#    #+#             */
/*   Updated: 2023/11/01 09:37:58 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words_count(char const *s, char c)
{
	size_t	i;
	size_t	in_word;
	size_t	words_count;

	if (!s)
		return (0);
	in_word = 0;
	words_count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!in_word)
			{
				in_word = 1;
				words_count++;
			}
		}
		else
			in_word = 0;
		i++;
	}
	return (words_count);
}

static size_t	ft_next_word_length(char const *s, char c, size_t *i)
{
	size_t	current_word_length;

	if (!s || !ft_isascii(c) || !i)
		return (0);
	while (s[*i] == c && s[*i] != '\0')
		(*i)++;
	current_word_length = 0;
	while (s[*i] != c && s[*i] != '\0')
	{
		current_word_length++;
		(*i)++;
	}
	return (current_word_length);
}

static void	ft_free_splitted(char **splitted, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		free(splitted[i]);
		i++;
	}
	free(splitted);
}

static char	**ft_fill_splitted(char const *s, char c, char **splitted_c,
		size_t words_count)
{
	size_t	i;
	size_t	current_word_length;
	size_t	splitted_pos;

	splitted_pos = 0;
	i = 0;
	while (splitted_pos < words_count)
	{
		current_word_length = ft_next_word_length(s, c, &i);
		splitted_c[splitted_pos] = malloc(sizeof(char) * (1
					+ current_word_length));
		if (!splitted_c[splitted_pos])
		{
			ft_free_splitted(splitted_c, splitted_pos);
			return (NULL);
		}
		ft_strlcpy(splitted_c[splitted_pos], s + i - current_word_length,
			current_word_length + 1);
		splitted_pos++;
	}
	splitted_c[splitted_pos] = NULL;
	return (splitted_c);
}

char	**ft_split(char const *s, char c)
{
	size_t	words_count;
	char	**splitted_c;

	if (!s)
		return (NULL);
	words_count = ft_words_count(s, c);
	splitted_c = malloc(sizeof(char *) * (words_count + 1));
	if (!splitted_c)
		return (NULL);
	return (ft_fill_splitted(s, c, splitted_c, words_count));
}
