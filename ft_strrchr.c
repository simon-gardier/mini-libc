/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:58:31 by setun             #+#    #+#             */
/*   Updated: 2023/10/20 20:24:50 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*pos;

	i = 0;
	pos = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			pos = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		pos = (char *)(s + i);
	return (pos);
}
