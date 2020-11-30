/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_value_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:38:43 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:38:45 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	============================================================================
**	|			UTILITIES FOR FORMING AN INSERT VALUE OF STRING TYPE  		   |
**	============================================================================
*/

#include "parse_utils.h"

/*
** Returns the length for insert value of type STRING
*/

int	get_string_value_len(t_value *value, int len)
{
	if (value->width > len)
		return (value->width);
	else
		return (len);
}

/*
**	Returns the count of zeros for insert value for STRING type
*/

int	string_zeros_count(t_value *value, int len)
{
	if (value->flags.zero && !value->flags.minus
		&& value->width > len)
		return (value->width - len);
	return (0);
}

/*
**	Returns the count of spaces for insert value for STRING type
*/

int	string_spaces_count(t_value *value, int len)
{
	if (value->flags.minus)
	{
		if (value->width > len)
			return (value->width - len);
	}
	else
	{
		if (!value->flags.zero && value->width > len)
			return (value->width - len);
	}
	return (0);
}
