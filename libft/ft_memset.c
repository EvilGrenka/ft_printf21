/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:39:10 by rnoriko           #+#    #+#             */
/*   Updated: 2021/05/01 11:52:39 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	mem_offset;

	mem_offset = 0;
	while (mem_offset < len)
	{
		*(unsigned char *)(b + mem_offset) = (unsigned char)c;
		mem_offset++;
	}
	return (b);
}
