/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:33:49 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:33:53 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |					 COMMON VALUE PARCING UTILITIES					 	   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Returns the total length of a number
*/

int		get_num_len(long int c)
{
	int	len;

	len = 0;
	while (c / 10)
	{
		c /= 10;
		len++;
	}
	return (c < 0 ? len + 2 : len + 1);
}

/*
**	Returns true if the passed argument is a specifier
*/

int		ft_isspec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
			c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

/*
**	Gets the address of a string and returns its precision
*/

int		get_value_precision(char *str, t_value *value, va_list args)
{
	int i;

	i = 1;
	if (str[i] == '*')
		value->precision = va_arg(args, int);
	else if (ft_isdigit(str[i]))
	{
		while (str[i] == '0' && !ft_isspec(str[i + 1]))
			i++;
		value->precision = ft_atoi(&str[i]);
		i += get_num_len(value->precision) - 1;
	}
	else
	{
		value->precision = 0;
		i--;
	}
	return (i);
}

/*
**	Gets the address per string and returns its width
*/

int		get_value_width(char *str, t_value *value)
{
	value->width = ft_atoi(str);
	return (get_num_len(value->width) - 1);
}

/*
**	Gets the address per string and returns its width using the argument
*/

void	value_width_from_arg(int arg, t_value *value)
{
	if (arg < 0)
	{
		value->flags.minus = 1;
		value->width = -arg;
	}
	else
		value->width = arg;
}
