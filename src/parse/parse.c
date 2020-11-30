/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:38:59 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 13:39:04 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |	 	PARSING ON FLAGS AND SPECIFICATIONS IN INSERT VALUE				   |
** =============================================================================
*/

#include "parse.h"

/*
**	Initializes a structure of type t_value
*/

static t_value	*init_value(void)
{
	t_value *value;

	if (!(value = (t_value *)malloc(sizeof(t_value))))
		return (NULL);
	value->insert_value = NULL;
	value->spec = 0;
	value->flags.zero = 0;
	value->flags.minus = 0;
	value->pos.start = -1;
	value->pos.end = -1;
	value->precision = -1;
	value->width = -1;
	return (value);
}

/*
**	Clears the value taken from arguments
*/

void			clear_value(t_value *value)
{
	if (value->insert_value)
		free(value->insert_value);
	free(value);
}

/*
**	Takes a string that starts with a % character and returns
** 						parsed element
*/

t_value			*get_value(char *str, va_list args, int index)
{
	t_value	*value;
	int		i;

	i = 0;
	if (!(value = init_value()))
		return (NULL);
	value->pos.start = index;
	while (!ft_isspec(str[++i]))
	{
		if (str[i] == '-')
			value->flags.minus = 1;
		else if (str[i] == '0')
			value->flags.zero = 1;
		else if (ft_isdigit(str[i]))
			i += get_value_width(str + i, value);
		else if (str[i] == '.')
			i += get_value_precision(str + i, value, args);
		else if (str[i] == '*')
			value_width_from_arg(va_arg(args, int), value);
	}
	value->spec = str[i];
	if (!(value->insert_value = get_insert_value(value, args)))
		return (NULL);
	value->pos.end = i + index;
	return (value);
}

/*
**	Returns a list with parsed values
*/

t_list			*get_parsed_values(char *str, va_list args)
{
	t_list	*list;
	t_value	*value;
	int		i;

	i = 0;
	list = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (!(value = get_value(&(str[i]), args, i)))
			{
				ft_lstclear(&list, (void *)clear_value);
				return (NULL);
			}
			ft_lstadd_back(&list, ft_lstnew(value));
			i = value->pos.end;
		}
		i++;
	}
	return (list);
}
