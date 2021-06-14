/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_cdin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:37:25 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 09:31:16 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_convert_c(va_list *ap, t_format_arg format_arg)
{
	char	*save;

	if (format_arg.length == 'l')
		save = ft_chrdup(va_arg(*ap, long));
	else
		save = ft_chrdup((unsigned char)va_arg(*ap, int));
	return (save);
}

char	*ft_convert_di(va_list *ap, t_format_arg *format_arg)
{
	char		*save;
	long long	result_num;

	result_num = 0;
	if (format_arg->length == 'l')
		result_num = va_arg(*ap, long int);
	else if (format_arg->length == 'L')
		result_num = va_arg(*ap, long long int);
	else if (format_arg->length == 'h')
		result_num = (short int)va_arg(*ap, int);
	else if (format_arg->length == 'H')
		result_num = (signed char)va_arg(*ap, int);
	else
		result_num = va_arg(*ap, int);
	save = ft_itoa(result_num);
	if (*save == '-')
		format_arg->minus = 1;
	return (save);
}

int	ft_convert_n(va_list *ap, size_t len, t_format_arg format_arg)
{
	t_length	lengths;

	if (format_arg.length == 'H')
		lengths.length_hh = va_arg(*ap, signed char *);
	else if (format_arg.length == 'h')
		lengths.length_h = va_arg(*ap, short int *);
	else if (format_arg.length == 'l')
		lengths.length_l = va_arg(*ap, long int *);
	else if (format_arg.length == 'L')
		lengths.length_ll = va_arg(*ap, long long int *);
	else if (format_arg.length == 0)
		lengths.length = va_arg(*ap, int *);
	if (format_arg.length == 'H' && lengths.length_hh)
		*lengths.length_hh = len;
	else if (format_arg.length == 'h' && lengths.length_h)
		*lengths.length_h = len;
	else if (format_arg.length == 'l' && lengths.length_l)
		*lengths.length_l = len;
	else if (format_arg.length == 'L' && lengths.length_ll)
		*lengths.length_ll = len;
	else if (format_arg.length == 0 && lengths.length)
		*lengths.length = len;
	return (0);
}
