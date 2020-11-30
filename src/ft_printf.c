/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 13:28:51 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 13:28:55 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** =============================================================================
** |							MAIN FUNCTION FT_PRINTF						   |
** =============================================================================
*/

#include "ft_printf.h"

/*
**	Returns true if value start position is equal to arg value
*/

int	is_value_start(t_value *value, int i)
{
	if (value->pos.start == i)
		return (1);
	return (0);
}

/*
**	Writes the value of the insert to standard output and
** 				returns how much is inserted
*/

int	write_in_stdout(t_value *value)
{
	write(1, value->insert_value, value->len);
	return (value->len);
}

/*
**	Get end of the insert value position
*/

int	get_value_end_pos(t_value *value)
{
	return (value->pos.end);
}

/*
**	The main function duplicates the behavior of the original printf
*/

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		j;
	t_list	*begin_list;
	t_list	*values;

	i = -1;
	j = 0;
	va_start(args, str);
	values = get_parsed_values((char *)str, args);
	begin_list = values;
	while (str[++i])
	{
		if (values && is_value_start(values->content, i))
		{
			j += write_in_stdout(values->content);
			i = get_value_end_pos(values->content);
			values = values->next;
		}
		else if (str[i] && ++j)
			write(1, &(str[i]), 1);
	}
	ft_lstclear(&begin_list, (void *)clear_value);
	va_end(args);
	return (j);
}
