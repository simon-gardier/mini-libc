/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:37:29 by sgardier          #+#    #+#             */
/*   Updated: 2024/02/12 12:37:29 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_print_integer(int to_print)
{
	unsigned long long	to_print_abs;
	int					count;

	count = 0;
	to_print_abs = to_print;
	if (to_print < 0)
	{
		count += write(1, "-", 1);
		to_print_abs = -(unsigned long long)to_print;
	}
	return (count + ft_print_positive_number(to_print_abs, 10, 0));
}

int	ft_print_unsigned_integer(unsigned int to_print)
{
	return (ft_print_positive_number((unsigned long long)to_print, 10, 0));
}

int	ft_print_hex_lower(unsigned int to_print)
{
	return (ft_print_positive_number((unsigned long long)to_print, 16, 0));
}

int	ft_print_hex_upper(unsigned int to_print)
{
	return (ft_print_positive_number((unsigned long long)to_print, 16, 1));
}
