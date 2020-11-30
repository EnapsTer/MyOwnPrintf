/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_value_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:28:02 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:28:03 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |			UTILITIES FOR FORMING AN INSERT VALUE OF INTEGER TYPE  		   |
** =============================================================================
*/

#include "parse_utils.h"

/*
** Based on the parsef data, it returns the total length of the insert
** 								values
*/

int	get_integer_value_len(t_value *value, long int num)
{
	int n;

	n = get_num_len(num);
	if (value->precision >= value->width && value->precision >= n)
		return (num >= 0 ? value->precision : value->precision + 1);
	else if (value->width >= value->precision && value->width >= n)
		return (value->width);
	else if (value->precision == 0 && num == 0)
		return (0);
	else if (n >= value->width && n >= value->precision)
		return (n);
	return (0);
}

/*
** Based on parsed data returns the total number of zeros
** 					for substituted value
*/

int	integer_zeros_count(t_value *value, long int num)
{
	int num_len;

	if (value->precision == 0 && num == 0)
		num_len = 0;
	else
		num_len = num < 0 ? get_num_len(num) - 1 : get_num_len(num);
	if (value->precision - num_len > 0)
		return (value->precision - num_len);
	else if (value->flags.zero && !value->flags.minus &&
				value->width - num_len > 0 && value->precision < 0)
	{
		if (num < 0)
			return (value->width - num_len - 1);
		return (value->width - num_len);
	}
	return (0);
}

/*
** Returns the total number of spaces based on the parsed data
** 						 for insert value
*/

int	integer_spaces_count(t_value *value, int long num, int zeros_cnt)
{
	int num_len;

	if (value->precision == 0 && num == 0)
		num_len = 0;
	else
		num_len = get_num_len(num);
	if (value->width - zeros_cnt - num_len > 0)
		return (value->width - zeros_cnt - num_len);
	return (0);
}
