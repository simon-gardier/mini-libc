/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 19:58:29 by setun             #+#    #+#             */
/*   Updated: 2023/11/01 10:17:09 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	void	*memory_allocated;

	memory_allocated = malloc(count * size);
	if (!memory_allocated)
	{
		return (NULL);
	}
	ft_bzero(memory_allocated, count * size);
	return (memory_allocated);
}
