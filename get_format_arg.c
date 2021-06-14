/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_format_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:49:24 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/13 15:55:47 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format_arg	ft_init_format_arg(char character, long num)
{
	t_format_arg	format_arg;

	format_arg.flag = character;
	format_arg.width = num;
	format_arg.precision = -1;
	format_arg.spec_type = character;
	format_arg.field = num;
	format_arg.show = num;
	format_arg.minus = num;
	format_arg.length = character;
	format_arg.plus = character;
	format_arg.sharp = character;
	format_arg.sharp_x = num;
	return (format_arg);
}

t_format_arg	ft_get_flag(const char **format, t_format_arg format_arg)
{
	while (**format == '0' || **format == '-' || **format == '#'
		|| **format == ' ' || **format == '+')
	{
		if (**format == '0' || **format == '-')
		{
			if (format_arg.flag == '-')
			{
				(*format)++;
				continue ;
			}
			format_arg.flag = **format;
			(*format)++;
		}
		else if (**format == '#')
		{
			format_arg.sharp = **format;
			(*format)++;
		}
		else if (**format == ' ' || **format == '+')
		{
			format_arg.plus |= **format;
			(*format)++;
		}
	}
	return (format_arg);
}

t_format_arg	ft_get_field(const char **format, va_list *ap,
				t_format_arg format_arg)
{
	long	field;

	field = 0;
	if (**format == '*')
	{
		(*format)++;
		field = va_arg(*ap, int);
		if (field < 0)
			format_arg.flag = '-';
	}
	else if (**format != '0')
	{
		while (ft_isdigit(**format))
		{
			field = field * 10 + **format - '0';
			(*format)++;
		}
	}
	format_arg.field = ft_abs(field);
	return (format_arg);
}

long	ft_get_precision(const char **format, va_list *ap)
{
	long	precision;
	int		sign;

	precision = 0;
	sign = 1;
	if (**format == '.')
	{
		(*format)++;
		if (**format == '*')
		{
			(*format)++;
			return (va_arg(*ap, int));
		}
		if (**format == '-')
			sign = -1;
		if (**format == '-')
			(*format)++;
		while (ft_isdigit(**format))
		{
			precision = precision * 10 + (**format - '0');
			(*format)++;
		}
		return (precision * sign);
	}
	return (-1);
}

char	get_length(const char **format)
{
	if (**format == 'h')
	{
		(*format)++;
		if (**format == 'h')
		{
			(*format)++;
			return ('H');
		}
		else
			return ('h');
	}
	else if (**format == 'l')
	{
		(*format)++;
		if (**format == 'l')
		{
			(*format)++;
			return ('L');
		}
		else
			return ('l');
	}
	return (0);
}
