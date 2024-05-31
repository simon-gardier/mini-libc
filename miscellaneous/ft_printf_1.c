/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 17:02:34 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/17 17:02:34 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

int	ft_print_character(char to_print, int *error)
{
	if (write(FT_PRINTF_OUT, &to_print, 1) == -1)
		return (*error = 1, (0));
	return (1);
}

int	ft_print_integer(int to_print, int *error)
{
	unsigned long long	to_print_abs;
	int					count;

	count = 0;
	to_print_abs = to_print;
	if (to_print < 0)
	{
		count = write(1, "-", 1);
		if (count == -1)
			return (*error = 1, (0));
		to_print_abs = -(unsigned long long)to_print;
	}
	return (count + ft_print_ull(to_print_abs, 10, "0123456789", error));
}

int	ft_print_string(char *to_print, int *error)
{
	int	count;

	if (to_print == NULL)
	{
		count = write(FT_PRINTF_OUT, "(null)", 6);
		if (count == -1)
			return (*error = 1, (0));
		return (count);
	}
	count = write(FT_PRINTF_OUT, to_print, ft_strlen(to_print));
	if (count == -1)
		return (*error = 1, (0));
	return (count);
}

int	ft_print_pointer(unsigned long long to_print, int *error)
{
	int	count;

	count = write(FT_PRINTF_OUT, "0x", 2);
	if (count == -1)
		return (*error = 1, (0));
	return (count + ft_print_ull(to_print, 16, "0123456789abcdef", error));
}

int	ft_print_ull(unsigned long long number, int base, char *symbols,
		int *error)
{
	static char	representation[64];
	char		*repr_position;
	int			count;

	repr_position = &representation[sizeof(representation) - 1];
	*repr_position = '\0';
	*(repr_position - 1) = '0';
	if (number == 0)
	{
		count = write(FT_PRINTF_OUT, "0", 1);
		if (count == -1)
			return (*error = 1, (0));
		return (1);
	}
	while (number > 0)
	{
		*(--repr_position) = symbols[number % base];
		number /= base;
	}
	count = write(FT_PRINTF_OUT, repr_position, ft_strlen(repr_position));
	if (count == -1)
		return (*error = 1, (0));
	return (count);
}
