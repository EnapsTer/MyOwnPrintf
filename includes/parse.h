/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:47:54 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:47:59 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PROJECT_PARSE_H
# define PRINTF_PROJECT_PARSE_H
# include "ft_printf.h"
# define HEX "0123456789abcdef"
# define UPPER_HEX "0123456789ABCDEF"

/*
**	Parse values functions
*/

char	*get_insert_value(t_value *value, va_list args);

char	*integer_parser(t_value *value, long int num);

char	*string_parser(t_value *value, char *str);

char	*char_parser(t_value *value, char c);

char	*pointer_parser(uint64_t address, t_value *value, char *base);

char	*hex_parser(uint32_t address, t_value *value, char *base);

/*
**	Utils for parsing
*/

int		ft_isspec(char c);

int		get_value_precision(char *str, t_value *value, va_list args);

int		get_value_width(char *str, t_value *value);

void	value_width_from_arg(int arg, t_value *value);

#endif
