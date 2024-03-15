/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:37:54 by sgardier          #+#    #+#             */
/*   Updated: 2024/02/12 12:37:54 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "ft_printf.h"

unsigned int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*ft_positive_number_to_string(unsigned long long number, int base,
		unsigned int upper_case)
{
	static char	representation[17];
	char		*position;

	position = &representation[sizeof(representation) - 1];
	*position = '\0';
	*(position - 1) = '0';
	if (number == 0)
		return (--position);
	while (number > 0)
	{
		if (upper_case)
			*(--position) = "0123456789ABCDEF"[number % base];
		else
			*(--position) = "0123456789abcdef"[number % base];
		number /= base;
	}
	return (position);
}

unsigned int	ft_print_positive_number(unsigned long long number, int base,
		unsigned int upper_case)
{
	char	*representation;

	representation = ft_positive_number_to_string(number, base, upper_case);
	return (write(1, representation, ft_strlen(representation)));
}
