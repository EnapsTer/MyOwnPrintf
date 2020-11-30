/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:51:04 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:51:06 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PROJECT_PARSE_UTILS_H
# define PRINTF_PROJECT_PARSE_UTILS_H
# include "ft_printf.h"

/*
**	Parse utils for base numbers type
*/

int		get_num_base_len(char *num, t_value *value, int addition);

char	*ft_itoa_base(uint64_t n, char *base);

int		ft_nbrlen_base(uint64_t n, int base_len);

int		base_zeros_count(t_value *value, char *num, int addition);

int		base_spaces_count(t_value *value, char *num, int zeros, int addition);

/*
**	Parse utils for numbers type
*/

int		get_num_len(long int c);

int		get_integer_value_len(t_value *value, long int num);

int		integer_zeros_count(t_value *value, long int num);

int		integer_spaces_count(t_value *value, long int num, int zeros_cnt);

/*
**	Parse utils for string type
*/

int		get_string_value_len(t_value *value, int len);

int		string_zeros_count(t_value *value, int len);

int		string_spaces_count(t_value *value, int len);

#endif
