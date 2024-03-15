/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 23:41:43 by setun             #+#    #+#             */
/*   Updated: 2023/10/20 20:21:27 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_move_before(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
}

static void	ft_move_after(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len - 1;
	while (i >= 0)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		if (i == 0)
			break ;
		i--;
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (len == 0)
		return (dst);
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		ft_move_before(dst, src, len);
	else
		ft_move_after(dst, src, len);
	return (dst);
}
