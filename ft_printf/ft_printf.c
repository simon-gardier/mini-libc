/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 12:44:26 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/15 14:58:40 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	ft_handle_percentage(char *format, va_list *args)
{
	int	count;

	if (format[1] == 'c')
		count = ft_print_character((char)va_arg(*args, int));
	else if (format[1] == 's')
		count = ft_print_string((char *)va_arg(*args, char *));
	else if (format[1] == 'p')
		count = ft_print_pointer((unsigned long long)va_arg(*args,
					unsigned long long));
	else if (format[1] == 'd')
		count = ft_print_integer((int)va_arg(*args, int));
	else if (format[1] == 'i')
		count = ft_print_integer((int)va_arg(*args, int));
	else if (format[1] == 'u')
		count = ft_print_unsigned_integer((unsigned int)va_arg(*args,
					unsigned int));
	else if (format[1] == 'x')
		count = ft_print_hex_lower((unsigned int)va_arg(*args, unsigned int));
	else if (format[1] == 'X')
		count = ft_print_hex_upper((unsigned int)va_arg(*args, unsigned int));
	else
		count = ft_print_character(format[1]);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		char_count;
	int		i;

	i = 0;
	va_start(args, format);
	i = 0;
	char_count = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			char_count += ft_handle_percentage((char *)(format + i), &args);
			i += 2;
		}
		else
		{
			char_count += ft_print_character(format[i]);
			i++;
		}
	}
	va_end(args);
	return (char_count);
}
