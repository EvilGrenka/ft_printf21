/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:51:59 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/13 15:56:18 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putout(char *save, t_format_arg format_arg)
{
	if (format_arg.flag == 'L')
		ft_putleft(save, format_arg);
	else if (format_arg.flag == '0')
		ft_putzero(save, format_arg);
	else if (format_arg.flag == 'R')
		ft_putright(save, format_arg);
	if (save)
		free(save);
}

void	ft_putzero(char *save, t_format_arg format_arg)
{
	while (format_arg.field > format_arg.show)
	{
		ft_putchar_fd(' ', 1);
		format_arg.field--;
	}
	if (format_arg.spec_type == 'p' || format_arg.sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		format_arg.field -= 2;
		format_arg.width -= 2;
		format_arg.show -= 2;
	}
	if (format_arg.minus || format_arg.plus)
	{
		ft_putchar_fd(*save++, 1);
		format_arg.field--;
		format_arg.width--;
		format_arg.show--;
	}
	while (format_arg.show-- > format_arg.width)
		ft_putchar_fd('0', 1);
	while (format_arg.width--)
		ft_putchar_fd(*save++, 1);
	return ;
}

long	ft_max (long a, long b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

long	ft_min(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long	ft_abs (long a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}
