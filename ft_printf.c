/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 14:59:36 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 09:42:26 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	size_t	writen_characters;

	writen_characters = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			writen_characters += ft_parse(&format, &ap, writen_characters);
		}
		else
		{
			ft_putchar_fd(*format++, 1);
			writen_characters++;
		}
	}
	va_end(ap);
	return (writen_characters);
}

int	ft_parse(const char **format, va_list *ap, size_t len)
{
	t_format_arg	format_arg;

	format_arg = ft_init_format_arg(0, 0);
	format_arg = ft_get_flag(format, format_arg);
	format_arg = ft_get_field(format, ap, format_arg);
	format_arg.precision = ft_get_precision(format, ap);
	format_arg.length = get_length(format);
	format_arg.spec_type = **format;
	if (format_arg.flag == '-')
		format_arg.flag = 'L';
	else if (format_arg.flag == '0')
		format_arg.flag = '0';
	else
		format_arg.flag = 'R';
	if (ft_is_spec_type(**format))
		(*format)++;
	return (ft_save(ap, format_arg, len));
}

int	ft_save(va_list *ap, t_format_arg format_arg, size_t len)
{
	char	*save;

	if (format_arg.spec_type == 'c')
		save = ft_convert_c(ap, format_arg);
	else if (format_arg.spec_type == 's')
		if (format_arg.flag == '0')
			save = ft_strdup("");
	else if (format_arg.length == 'l')
		save = ft_convert_string((int *)va_arg(*ap, char *));
	else
		save = ft_strdup((char *)va_arg(*ap, char *));
	else if (format_arg.spec_type == 'd' || format_arg.spec_type == 'i')
		save = ft_convert_di(ap, &format_arg);
	else if (ft_isnump(format_arg.spec_type))
		save = ft_convert_uxp(ap, format_arg);
	else if (format_arg.spec_type == '%')
		save = ft_strdup("%");
	else if (format_arg.spec_type == 'n')
		return (ft_convert_n(ap, len, format_arg));
	else
		return (0);
	if (!save)
		save = ft_strdup("(null)");
	return (ft_save_putout(format_arg, save));
}

static t_format_arg	ft_get_show(t_format_arg format_arg, char *save)
{
	if (ft_isnump(format_arg.spec_type) && format_arg.flag == '0'
		&& format_arg.precision < 0)
		format_arg.show = ft_max(format_arg.field, format_arg.width);
	else if (format_arg.spec_type == 'p' || format_arg.sharp_x)
		format_arg.show = ft_max(format_arg.width, format_arg.precision + 2);
	else if (ft_isnum(format_arg.spec_type))
		format_arg.show = ft_max(format_arg.width, format_arg.precision
				+ ((format_arg.minus + format_arg.plus) != 0));
	else if (format_arg.flag == '0')
		format_arg.show = ft_max(format_arg.field, format_arg.width);
	else if ((format_arg.spec_type == 'c' || format_arg.spec_type == '%')
		&& format_arg.length == 'l')
		format_arg.show = ft_strlen(save);
	else if (format_arg.spec_type == 'c' || format_arg.spec_type == '%')
		format_arg.show = 1;
	else if (format_arg.precision < 0)
		format_arg.show = format_arg.width;
	else
		format_arg.show = ft_min(format_arg.precision, format_arg.width);
	return (format_arg);
}

int	ft_save_putout(t_format_arg f_arg, char *save)
{	
	if (ft_isnum(f_arg.spec_type)
		&& f_arg.precision == 0 && !ft_strncmp(save, "0\0", 2))
		*save = '\0';
	if (f_arg.sharp)
		save = ft_sharp(save, &f_arg);
	if (f_arg.plus && !f_arg.minus && ft_isnum(f_arg.spec_type))
		save = ft_addplus_space(save, f_arg);
	f_arg.width = ft_strlen(save);
	f_arg = ft_get_show(f_arg, save);
	f_arg.field = ft_max(f_arg.field, f_arg.show);
	ft_putout(save, f_arg);
	return (f_arg.field);
}
