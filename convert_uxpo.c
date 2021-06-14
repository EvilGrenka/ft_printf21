/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_uxp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:43:30 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/13 15:53:59 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_st(size_t num)
{
	char		*result;
	int			len_num;
	size_t		tmp;

	len_num = 1;
	tmp = num;
	tmp /= 10;
	while (tmp)
	{
		len_num++;
		tmp /= 10;
	}
	result = (char *)malloc(sizeof(char) * len_num + 1);
	if (!result)
		return (NULL);
	result[len_num] = '\0';
	result[--len_num] = num % 10 + '0';
	num /= 10;
	while (num)
	{
		result[--len_num] = num % 10 + '0';
		num /= 10;
	}
	return (result);
}

char	*ft_convert_p(size_t num, char *set, t_format_arg format_arg)
{
	char	*save;
	char	*prefix;
	char	*result;

	prefix = ft_strdup("0x");
	if (!num && format_arg.precision == 0)
		result = ft_strdup("");
	else if (!num)
		result = ft_strdup("0");
	else
		result = ft_convert(num, set, 16);
	save = ft_strjoin(prefix, result);
	if (prefix)
		free(prefix);
	if (result)
		free(result);
	return (save);
}

char	*ft_convert(size_t num, const char *set, int base)
{
	char	*result;
	int		len_num;
	size_t	tmp;

	tmp = num;
	len_num = 1;
	tmp /= base;
	while (tmp)
	{
		len_num++;
		tmp /= base;
	}
	result = (char *)malloc(sizeof(char) * len_num + 1);
	if (!result)
		return (NULL);
	result[len_num] = '\0';
	result[--len_num] = set[num % base];
	num /= base;
	while (num)
	{
		result[--len_num] = set[num % base];
		num /= base;
	}
	return (result);
}

char	*ft_convert_uxp(va_list *ap, t_format_arg format_arg)
{
	char	*save;
	size_t	result_num;

	result_num = 0;
	if (format_arg.length == 'L' || format_arg.spec_type == 'p')
		result_num = va_arg(*ap, unsigned long long int);
	else if (format_arg.length == 'l')
		result_num = va_arg(*ap, unsigned long int);
	else if (format_arg.length == 'h')
		result_num = (unsigned short int)va_arg(*ap, unsigned int);
	else if (format_arg.length == 'H')
		result_num = (unsigned char)va_arg(*ap, unsigned int);
	else
		result_num = va_arg(*ap, unsigned int);
	if (format_arg.spec_type == 'u')
		save = ft_itoa_st(result_num);
	if (format_arg.spec_type == 'o')
		save = ft_convert(result_num, "01234567", 8);
	if (format_arg.spec_type == 'x')
		save = ft_convert(result_num, "0123456789abcdef", 16);
	if (format_arg.spec_type == 'X')
		save = ft_convert(result_num, "0123456789ABCDEF", 16);
	if (format_arg.spec_type == 'p')
		save = ft_convert_p(result_num, "0123456789abcdef", format_arg);
	return (save);
}
