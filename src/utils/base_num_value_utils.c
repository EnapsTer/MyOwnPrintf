/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_num_value_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:37:03 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 14:37:06 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |					  UTILS FOR WORKING WITH ANOTHER SS					   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Returns zeros count for forming insert string for type POINTER and HEX
*/

int		base_zeros_count(t_value *value, char *num, int addition)
{
	int num_len;

	num_len = ft_strlen(num);
	if (value->precision > num_len)
		return (value->precision - num_len);
	else if (value->precision == -1 && value->flags.zero && !value->flags.minus
				&& value->width > num_len + addition)
		return (value->width - num_len - addition);
	return (0);
}

/*
**	Returns spaces count for forming insert string for type POINTER and HEX
*/

int		base_spaces_count(t_value *value, char *num, int zeros, int addition)
{
	int num_len;

	num_len = ft_strlen(num);
	if (value->width > num_len + zeros + addition)
		return (value->width - num_len - zeros - addition);
	return (0);
}

/*
**	Returns length for insert string for type POINTER and HEX
*/

int		get_num_base_len(char *num, t_value *value, int addition)
{
	int num_len;
	int num_len_with_prec;

	num_len = ft_strlen(num);
	if (value->precision > num_len)
		num_len_with_prec = value->precision + addition;
	else
		num_len_with_prec = num_len + addition;
	if (value->width > num_len_with_prec)
		return (value->width);
	else
		return (num_len_with_prec);
}

/*
**	Returns length for type POINTER and HEX
*/

int		ft_nbrlen_base(uint64_t n, int base_len)
{
	int len;

	if (!base_len)
		return (0);
	if (n == 0)
		return (1);
	len = 0;
	while (n)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

/*
**	Converts the num to base view and returns it
*/

char	*ft_itoa_base(uint64_t n, char *base)
{
	char	*result;
	int		number_len;
	int		base_len;

	base_len = ft_strlen(base);
	number_len = ft_nbrlen_base(n, base_len);
	if (!(result = (char *)malloc(number_len + 1)))
		return (NULL);
	result[number_len] = '\0';
	while (number_len--)
	{
		result[number_len] = base[n % base_len];
		n /= base_len;
	}
	return (result);
}
