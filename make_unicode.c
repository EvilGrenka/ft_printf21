/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_unicode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:30:29 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 09:42:59 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_chrdup(long n)
{
	char	*chr;
	int		size;
	int		i;

	size = ft_wbyte(n);
	chr = (char *)malloc(sizeof(char ) * size + 1);
	if (!chr)
		return (NULL);
	i = size;
	chr[i] = '\0';
	while (--i)
	{
		chr[i] = (X8 + n % X7);
		n /= X7;
	}
	chr[0] = ft_wbyte_topindex(size, n);
	return (chr);
}

int	ft_wbyte(long n)
{
	int	i;

	if (n <= 255)
		return (1);
	i = 0;
	if (n >= FC5)
		i++;
	if (n >= FC4)
		i++;
	if (n >= FC3)
		i++;
	if (n >= FC2)
		i++;
	if (n >= FC1)
		i++;
	i++;
	return (i);
}

int	ft_wbyte_topindex(int size, long n)
{
	if (size == 1)
		return (n);
	else if (size == 2)
		return (0b11000000 + n);
	else if (size == 3)
		return (0b11100000 + n);
	else if (size == 4)
		return (0b11110000 + n);
	else if (size == 5)
		return (0b11111000 + n);
	else if (size == 6)
		return (0b11111100 + n);
	else
		return (0);
}

char	*ft_convert_string(int *string)
{
	char	*result_str;
	char	*tmp;
	char	*control_leaks;

	if (!*string)
		return (ft_strdup(""));
	result_str = ft_chrdup((long)*string);
	string++;
	while (*string)
	{
		tmp = ft_chrdup((long )*string);
		control_leaks = result_str;
		result_str = ft_strjoin(result_str, tmp);
		free(control_leaks);
		free(tmp);
		string++;
	}
	return (result_str);
}
