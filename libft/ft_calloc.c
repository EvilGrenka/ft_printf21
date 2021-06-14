/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:11:32 by rnoriko           #+#    #+#             */
/*   Updated: 2021/05/01 11:51:54 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*memory_alloc;

	memory_alloc = malloc(size * count);
	if (!memory_alloc)
		return (NULL);
	ft_memset(memory_alloc, 0, count * size);
	return (memory_alloc);
}
