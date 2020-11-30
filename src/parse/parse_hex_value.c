/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex_value.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:04:19 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 14:04:21 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |				    FORMING A INSERT VALUE TYPE STRING				 	   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Fills in a string for a insert value with a minus flag
*/

static void	fill_minus_string(char **result, char *num, t_value *value)
{
	int zeros;
	int spaces;
	int i;

	zeros = base_zeros_count(value, num, 0);
	spaces = base_spaces_count(value, num, zeros, 0);
	i = 0;
	while (zeros--)
		(*result)[i++] = '0';
	while (*num)
		(*result)[i++] = *num++;
	while (spaces--)
		(*result)[i++] = ' ';
	(*result)[i] = '\0';
}

/*
**	Fills in a string for a substituted value without a minus flag
*/

static void	fill_string(char **result, char *num, t_value *value)
{
	int zeros;
	int spaces;
	int i;

	zeros = base_zeros_count(value, num, 0);
	spaces = base_spaces_count(value, num, zeros, 0);
	i = 0;
	while (spaces--)
		(*result)[i++] = ' ';
	while (zeros--)
		(*result)[i++] = '0';
	while (*num)
		(*result)[i++] = *num++;
	(*result)[i] = '\0';
}

/*
**	Constructs a insert string of type HEX value from the parsed data
**							and returns it
*/

char		*hex_parser(uint32_t address, t_value *value, char *base)
{
	char	*result;
	char	*num;

	if (!address && value->precision == 0)
		num = "";
	else
		num = ft_itoa_base(address, base);
	value->len = get_num_base_len(num, value, 0);
	if (!(result = (char *)malloc(
			sizeof(char) * (value->len + 1))))
		return (NULL);
	if (value->flags.minus)
		fill_minus_string(&result, num, value);
	else
		fill_string(&result, num, value);
	return (result);
}
