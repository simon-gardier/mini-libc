/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 13:59:35 by sgardier          #+#    #+#             */
/*   Updated: 2023/10/20 14:58:27 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_length;
	char			*res;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_length = ft_strlen(s);
	res = malloc(sizeof(char) * (s_length + 1));
	if (!res)
		return (NULL);
	while (i < s_length)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[s_length] = '\0';
	return (res);
}
