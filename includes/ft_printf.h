/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aherlind <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 15:39:46 by aherlind          #+#    #+#             */
/*   Updated: 2020/11/29 15:39:47 by aherlind         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_PROJECT_FT_PRINTF_H
# define PRINTF_PROJECT_FT_PRINTF_H
# include <stdarg.h>
# include "ft_printf_structers.h"
# include "libft.h"

/*
**	Main functions
*/

int		ft_printf(const char *str, ...);

t_list	*get_parsed_values(char *str, va_list args);

void	clear_value(t_value *value);

#endif
