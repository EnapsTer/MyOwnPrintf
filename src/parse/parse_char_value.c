/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:59:22 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 13:59:25 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |				   	FORMING A INSERT VALUE TYPE CHAR		  		 	   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Fills in a string for a insert value with a minus flag
*/

static void	fill_minus_string(char **result, char c, t_value *value)
{
	int zeros;
	int spaces;
	int i;

	zeros = string_zeros_count(value, 1);
	spaces = string_spaces_count(value, 1);
	i = 0;
	while (zeros--)
		(*result)[i++] = '0';
	(*result)[i++] = c;
	while (spaces--)
		(*result)[i++] = ' ';
	(*result)[i] = '\0';
}

/*
**	Fills in a string for a substituted value without a minus flag
*/

static void	fill_string(char **result, char c, t_value *value)
{
	int zeros;
	int spaces;
	int i;

	zeros = string_zeros_count(value, 1);
	spaces = string_spaces_count(value, 1);
	i = 0;
	while (spaces--)
		(*result)[i++] = ' ';
	while (zeros--)
		(*result)[i++] = '0';
	(*result)[i++] = c;
	(*result)[i] = '\0';
}

/*
**	Constructs a insert string of type CHAR value from the parsed data
**	 						and returns it
*/

char		*char_parser(t_value *value, char c)
{
	char *result;

	value->len = get_string_value_len(value, 1);
	if (!(result = (char *)malloc(
			sizeof(char) * (value->len + 1))))
		return (NULL);
	if (value->flags.minus)
		fill_minus_string(&result, c, value);
	else
		fill_string(&result, c, value);
	return (result);
}
