/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_string_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:19:32 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 14:19:42 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |				   	FORMING A INSERT VALUE TYPE STRING		  		 	   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Fills in a string for a insert value with a minus flag
*/

static void	fill_minus_string(char **result, char *str, t_value *value, int len)
{
	int zeros;
	int spaces;
	int i;

	zeros = string_zeros_count(value, len);
	spaces = string_spaces_count(value, len);
	i = 0;
	while (zeros--)
		(*result)[i++] = '0';
	while (*str && len--)
		(*result)[i++] = *str++;
	while (spaces--)
		(*result)[i++] = ' ';
	(*result)[i] = '\0';
}

/*
**	Fills in a string for a substituted value without a minus flag
*/

static void	fill_string(char **result, char *str, t_value *value, int len)
{
	int zeros;
	int spaces;
	int i;

	zeros = string_zeros_count(value, len);
	spaces = string_spaces_count(value, len);
	i = 0;
	while (spaces--)
		(*result)[i++] = ' ';
	while (zeros--)
		(*result)[i++] = '0';
	while (*str && len--)
		(*result)[i++] = *str++;
	(*result)[i] = '\0';
}

/*
**	Constructs a insert string of type STRING value from the parsed data
**	 						and returns it
*/

char		*string_parser(t_value *value, char *str)
{
	char	*result;
	int		len;

	if (!str)
		str = "(null)";
	if (value->precision >= 0 && value->precision < (int)ft_strlen(str))
		len = value->precision;
	else
		len = (int)ft_strlen(str);
	value->len = get_string_value_len(value, len);
	if (!(result = (char *)malloc(
			sizeof(char) * (value->len + 1))))
		return (NULL);
	if (value->flags.minus)
		fill_minus_string(&result, str, value, len);
	else
		fill_string(&result, str, value, len);
	return (result);
}
