/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:20:51 by setun             #+#    #+#             */
/*   Updated: 2023/10/20 14:33:05 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_number_length(unsigned long n)
{
	size_t	length;

	if (n < 10)
		return (1);
	length = 0;
	while (n > 0)
	{
		length++;
		n /= 10;
	}
	return (length);
}

static char	*ft_fill_representation(char *representation, size_t positionInRepr,
		unsigned long long number)
{
	if (!representation)
		return (NULL);
	representation[positionInRepr] = number % 10 + '0';
	if (number / 10 != 0)
		return (ft_fill_representation(representation, positionInRepr - 1,
				number / 10));
	return (representation);
}

char	*ft_itoa(int n)
{
	unsigned long long	n_absolute;
	unsigned int		negative;
	size_t				n_absolute_length;
	char				*representation;

	negative = 0;
	n_absolute = (unsigned long long)n;
	if (n < 0)
	{
		negative = 1;
		n_absolute *= -1;
	}
	n_absolute_length = ft_number_length(n_absolute);
	representation = malloc(sizeof(char) * (negative + n_absolute_length + 1));
	if (!representation)
		return (NULL);
	representation[n_absolute_length + negative] = '\0';
	if (negative)
		representation[0] = '-';
	return (ft_fill_representation(representation, n_absolute_length + negative
			- 1, n_absolute));
}
