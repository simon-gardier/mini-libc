/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:44:26 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/17 16:51:00 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdarg.h>

static int	ft_handle_percentage(char type, va_list *args, int *error)
{
	if (type == 'c')
		return (ft_print_character((char)va_arg(*args, int), error));
	else if (type == 's')
		return (ft_print_string(va_arg(*args, char *), error));
	else if (type == 'p')
		return (ft_print_pointer(va_arg(*args, unsigned long long), error));
	else if (type == 'd')
		return (ft_print_integer(va_arg(*args, int), error));
	else if (type == 'i')
		return (ft_print_integer(va_arg(*args, int), error));
	else if (type == 'u')
		return (ft_print_ull(va_arg(*args, unsigned int), 10, "0123456789",
				error));
	else if (type == 'x')
		return (ft_print_ull(va_arg(*args, unsigned int), 16,
				"0123456789abcdef", error));
	else if (type == 'X')
		return (ft_print_ull(va_arg(*args, unsigned int), 16,
				"0123456789ABCDEF", error));
	else
		return (ft_print_character(type, error));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total_count;
	int		error;
	int		i;

	i = 0;
	va_start(args, format);
	i = 0;
	total_count = 0;
	error = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			total_count += ft_handle_percentage((char)*(format + ++i), &args,
					&error);
		else
			total_count += ft_print_character(format[i], &error);
		if (error)
			return (total_count);
		i++;
	}
	va_end(args);
	return (total_count);
}
