/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:37:24 by sgardier          #+#    #+#             */
/*   Updated: 2024/02/12 12:37:24 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stddef.h>

int	ft_print_character(char to_print)
{
	return (write(1, &to_print, 1));
}

int	ft_print_string(char *to_print)
{
	if (to_print == NULL)
		return (write(1, "(null)", 6));
	return (write(1, to_print, ft_strlen(to_print)));
}

int	ft_print_pointer(unsigned long long to_print)
{
	return (write(1, "0x", 2) + ft_print_positive_number(to_print, 16, 0));
}
