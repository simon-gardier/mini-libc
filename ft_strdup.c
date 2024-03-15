/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 01:40:13 by setun             #+#    #+#             */
/*   Updated: 2023/10/20 14:54:44 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*s1_dup;
	size_t	i;
	size_t	s1_length;

	s1_length = ft_strlen(s1);
	s1_dup = malloc(sizeof(char) * (s1_length + 1));
	if (!s1_dup)
		return (NULL);
	i = 0;
	while (i < s1_length)
	{
		s1_dup[i] = s1[i];
		i++;
	}
	s1_dup[i] = '\0';
	return (s1_dup);
}
