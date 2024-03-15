/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 15:43:39 by sgardier          #+#    #+#             */
/*   Updated: 2023/10/20 15:04:18 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*substr;
	size_t	pos_in_substr;
	size_t	substr_len;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		substr_len = 0;
	else if (s_len - start >= len)
		substr_len = len;
	else
		substr_len = s_len - start;
	substr = malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	pos_in_substr = 0;
	while (pos_in_substr < substr_len)
	{
		substr[pos_in_substr] = s[start + pos_in_substr];
		pos_in_substr++;
	}
	substr[substr_len] = '\0';
	return (substr);
}
