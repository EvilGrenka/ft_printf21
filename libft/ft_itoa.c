/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 14:39:47 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/07 12:58:55 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_revers_str(char *str)
{
	size_t	len_str;
	size_t	i;
	char	tmpch;

	len_str = ft_strlen(str);
	i = 0;
	while (i < len_str / 2)
	{
		tmpch = str[i];
		str[i] = str[len_str - i - 1];
		str[len_str - i - 1] = tmpch;
		i++;
	}
}

static int	ft_module_nbr(long long nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

static size_t	ft_len_nbr(long long nbr, int negative_sign)
{
	size_t	len_nbr;

	len_nbr = 1;
	if (!nbr)
		len_nbr++;
	while (nbr)
	{
		len_nbr++;
		nbr /= 10;
	}
	return (len_nbr + negative_sign);
}

char	*ft_itoa(long long n)
{
	char	*tmpstr;
	int		negative_sign;
	size_t	len_str;

	negative_sign = 0;
	if (n < 0)
		negative_sign = 1;
	tmpstr = ft_calloc(ft_len_nbr(n, negative_sign), sizeof(char));
	if (!tmpstr)
		return (NULL);
	len_str = 0;
	if (!n)
		tmpstr[len_str++] = '0';
	while (n)
	{
		tmpstr[len_str++] = '0' + ft_module_nbr(n % 10);
		n /= 10;
	}
	if (negative_sign)
		tmpstr[len_str++] = '-';
	tmpstr[len_str] = '\0';
	ft_revers_str(tmpstr);
	return (tmpstr);
}
