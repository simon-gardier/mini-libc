/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 16:21:04 by sgardier          #+#    #+#             */
/*   Updated: 2023/11/01 10:16:27 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len_s1;
	int		len_s2;
	int		i;
	char	*strjoined;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	strjoined = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!strjoined)
		return (NULL);
	i = -1;
	while (++i < len_s1)
		strjoined[i] = s1[i];
	i = -1;
	while (++i < len_s2)
		strjoined[len_s1 + i] = s2[i];
	strjoined[len_s1 + len_s2] = '\0';
	return (strjoined);
}
