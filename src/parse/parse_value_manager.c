/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:27:12 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 14:27:14 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |						 MANAGER FOR INSERT VALUES					 	   |
** =============================================================================
*/

#include "parse.h"

/*
**	The function receives the parsed data and, based on the specifier, throws
**			to other functions that return a substituted value
*/

char	*get_insert_value(t_value *value, va_list args)
{
	char *result;

	result = NULL;
	if (value->spec == 'd' || value->spec == 'i')
		result = integer_parser(value, va_arg(args, int));
	else if (value->spec == 'u')
		result = integer_parser(value, va_arg(args, uint32_t));
	else if (value->spec == 's')
		result = string_parser(value, va_arg(args, char *));
	else if (value->spec == 'c')
		result = char_parser(value, va_arg(args, int));
	else if (value->spec == 'p')
		result = pointer_parser(va_arg(args, uint64_t), value, HEX);
	else if (value->spec == '%')
		result = char_parser(value, '%');
	else if (value->spec == 'x')
		result = hex_parser(va_arg(args, uint32_t), value, HEX);
	else if (value->spec == 'X')
		result = hex_parser(va_arg(args, uint32_t), value, UPPER_HEX);
	return (result);
}
