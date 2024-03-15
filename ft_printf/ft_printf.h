/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 10:29:14 by sgardier          #+#    #+#             */
/*   Updated: 2024/03/15 14:57:08 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
int				ft_printf(const char *format, ...);
//conversion.c
int				ft_print_character(char to_print);
int				ft_print_string(char *to_print);
int				ft_print_pointer(unsigned long long to_print);
//conversion_1.c
int				ft_print_integer(int to_print);
int				ft_print_unsigned_integer(unsigned int to_print);
int				ft_print_hex_lower(unsigned int to_print);
int				ft_print_hex_upper(unsigned int to_print);
//utils.c
unsigned int	ft_strlen(char *str);
unsigned int	ft_print_positive_number(unsigned long long number, int base,
					unsigned int upper_case);
#endif