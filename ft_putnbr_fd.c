/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:14:41 by sgardier          #+#    #+#             */
/*   Updated: 2023/10/20 20:22:54 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <unistd.h>

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

static unsigned long long	ft_power_of_10(int exponent)
{
	unsigned long long	power;

	if (exponent == 0)
		return (1);
	power = 1;
	while (exponent > 0)
	{
		power *= 10;
		exponent--;
	}
	return (power);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned long long	n_absolute;
	char				current_digit;
	size_t				number_length;

	n_absolute = n;
	if (n < 0)
	{
		write(fd, "-", 1);
		n_absolute *= -1;
	}
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	number_length = ft_number_length(n_absolute);
	while (number_length > 0)
	{
		current_digit = (n_absolute / ft_power_of_10(number_length - 1)) % 10
			+ '0';
		write(fd, &current_digit, 1);
		number_length--;
	}
}
