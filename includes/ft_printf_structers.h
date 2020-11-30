/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_structers.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:40:59 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:41:07 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PROJECT_FT_PRINTF_STRUCTERS_H
# define PRINTF_PROJECT_FT_PRINTF_STRUCTERS_H
# include <stdlib.h>

/*
**	Structures for parsing
*/

typedef struct	s_position
{
	int start;
	int end;
}				t_position;

typedef struct	s_flags
{
	int minus;
	int zero;
}				t_flags;

typedef struct	s_value
{
	t_position	pos;
	t_flags		flags;
	int			width;
	int			precision;
	int			len;
	char		spec;
	char		*insert_value;
}				t_value;

#endif
