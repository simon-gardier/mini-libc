/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:36:29 by setun             #+#    #+#             */
/*   Updated: 2023/10/20 20:08:34 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	size_t	i;

	if (!destination && !source)
		return (NULL);
	i = 0;
	while (i < size)
	{
		((unsigned char *)destination)[i] = ((unsigned char *)source)[i];
		i++;
	}
	return (destination);
}
