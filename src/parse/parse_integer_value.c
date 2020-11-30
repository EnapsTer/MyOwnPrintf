/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_integer_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 14:12:48 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 14:12:49 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |				  FORMING A INSERT VALUE TYPE INTEGER		  		 	   |
** =============================================================================
*/

#include "parse_utils.h"

/*
**	Fills in a string for a insert value with a minus flag
*/

static void	fill_minus_string(char **result, long int num, t_value *value)
{
	int		zeros;
	int		spaces;
	int		i;
	int		j;
	char	*str_num;

	zeros = integer_zeros_count(value, num);
	spaces = integer_spaces_count(value, num, zeros);
	i = 0;
	j = 0;
	str_num = ft_itoa(num);
	if (num < 0)
		(*result)[i++] = str_num[j++];
	while (zeros--)
		(*result)[i++] = '0';
	while (str_num[j] && (value->precision || num != 0))
		(*result)[i++] = str_num[j++];
	while (spaces--)
		(*result)[i++] = ' ';
	free(str_num);
	(*result)[i] = '\0';
}

/*
**	Fills in a string for a substituted value without a minus flag
*/

static void	fill_string(char **result, long int num, t_value *value)
{
	int		zeros;
	int		spaces;
	int		i;
	int		j;
	char	*str_num;

	zeros = integer_zeros_count(value, num);
	spaces = integer_spaces_count(value, num, zeros);
	i = 0;
	j = 0;
	str_num = ft_itoa(num);
	while (spaces--)
		(*result)[i++] = ' ';
	if (num < 0)
		(*result)[i++] = str_num[j++];
	while (zeros--)
		(*result)[i++] = '0';
	while (str_num[j] && (value->precision || num != 0))
		(*result)[i++] = str_num[j++];
	free(str_num);
	(*result)[i] = '\0';
}

/*
**	Constructs a insert string of type INTEGER value from the parsed data
**	 						and returns it
*/

char		*integer_parser(t_value *value, long int num)
{
	char	*result;

	value->len = get_integer_value_len(value, num);
	if (!(result = (char *)malloc(
			sizeof(char) * (value->len + 1))))
		return (NULL);
	if (value->flags.minus)
		fill_minus_string(&result, num, value);
	else
		fill_string(&result, num, value);
	return (result);
}
