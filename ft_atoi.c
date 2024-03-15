/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgardier <sgardier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 19:01:49 by sgardier          #+#    #+#             */
/*   Updated: 2023/11/01 10:06:31 by sgardier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_get_value(char const *str, int sign)
{
	long	value;
	long	prev_value;
	size_t	i;

	i = 0;
	value = 0;
	prev_value = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		value = (value * 10) + (str[i] - '0');
		if (sign == 1 && value < prev_value)
			return (-1);
		else if (sign == -1 && sign * prev_value < -10 && sign * value > 0)
			return (0);
		else
			prev_value = value;
		i++;
	}
	return ((int)(sign * value));
}

int	ft_atoi(char const *str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	return (ft_get_value(str, sign));
}
