/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prefix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/08 09:53:36 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/14 11:35:50 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sharp(char *save, t_format_arg *format_arg)
{
	char	*prefix;
	char	*tmp;

	if ((format_arg->spec_type == 'x' || format_arg->spec_type == 'X')
		&& *save && *save != '0')
		format_arg->sharp_x = 1;
	if (format_arg->spec_type == 'o' && *save != '0')
		prefix = ft_strdup("0");
	else if (format_arg->spec_type == 'x' && format_arg->sharp_x)
		prefix = ft_strdup("0x");
	else if (format_arg->spec_type == 'X' && format_arg->sharp_x)
		prefix = ft_strdup("0X");
	else
		return (save);
	tmp = save;
	save = ft_strjoin(prefix, save);
	free(prefix);
	free(tmp);
	return (save);
}

char	*ft_addplus_space(char *save, t_format_arg format_arg)
{
	char	*join_result;
	char	*pre_sign;
	long	c;

	c = (long)format_arg.plus;
	pre_sign = ft_chrdup(c);
	join_result = ft_strjoin(pre_sign, save);
	free(pre_sign);
	free(save);
	return (join_result);
}
