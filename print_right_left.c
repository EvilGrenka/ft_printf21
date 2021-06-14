/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_right_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:51:39 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 14:53:14 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putright(char *save, t_format_arg format_arg)
{
	while (format_arg.field > format_arg.show)
	{
		ft_putchar_fd(' ', 1);
		format_arg.field--;
	}
	if (ft_isnump(format_arg.spec_type))
		save = ft_putright_num(save, &format_arg);
	while (format_arg.show--)
		ft_putchar_fd(*save++, 1);
	return ;
}

char	*ft_putright_num(char *save, t_format_arg *format_arg)
{
	if (format_arg->spec_type == 'p' || format_arg->sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		format_arg->field -= 2;
		format_arg->width -= 2;
		format_arg->show -= 2;
	}
	if (format_arg->minus || format_arg->plus)
	{
		ft_putchar_fd(*save++, 1);
		format_arg->show--;
		format_arg->field--;
		format_arg->width--;
	}
	while (format_arg->show > format_arg->width && format_arg->field)
	{
		ft_putchar_fd('0', 1);
		format_arg->show--;
		format_arg->field--;
	}
	return (save);
}

void	ft_putleft(char *save, t_format_arg format_arg)
{
	if (!(ft_isnump(format_arg.spec_type)))
	{
		while (format_arg.show && format_arg.field)
		{
			ft_putchar_fd(*save++, 1);
			format_arg.show--;
			format_arg.field--;
		}
	}
	else
		ft_putleft_num(save, &format_arg);
	while (format_arg.field--)
		ft_putchar_fd(' ', 1);
}

void	ft_putleft_num(char *save, t_format_arg *format_arg)
{
	if (format_arg->spec_type == 'p' || format_arg->sharp_x)
	{
		ft_putchar_fd(*save++, 1);
		ft_putchar_fd(*save++, 1);
		format_arg->field -= 2;
		format_arg->width -= 2;
		format_arg->show -= 2;
	}
	if (format_arg->minus || format_arg->plus)
	{
		ft_putchar_fd(*save++, 1);
		format_arg->field--;
		format_arg->width--;
		format_arg->show--;
	}
	while (format_arg->field && (format_arg->show > format_arg->width))
	{
		ft_putchar_fd('0', 1);
		format_arg->field--;
		format_arg->show--;
	}
	while (format_arg->show-- && format_arg->field--)
		ft_putchar_fd(*save++, 1);
}
