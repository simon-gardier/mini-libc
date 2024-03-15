/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 00:25:35 by setun             #+#    #+#             */
/*   Updated: 2023/11/01 10:03:36 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	search_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	search_len = ft_min(len, ft_strlen(haystack));
	while (i < search_len)
	{
		j = i;
		while (j < search_len && needle[j - i] != '\0')
		{
			if (haystack[j] != needle[j - i])
				break ;
			j++;
		}
		if (needle[j - i] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}
