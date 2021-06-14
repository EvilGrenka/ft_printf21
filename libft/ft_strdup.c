/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnoriko <rnoriko@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 13:22:41 by rnoriko           #+#    #+#             */
/*   Updated: 2021/06/02 14:37:11 by rnoriko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str_heap;
	size_t	i;

	if (!s1)
		return (NULL);
	str_heap = (char *)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
	if (str_heap)
	{
		i = 0;
		while (s1[i])
		{
			str_heap[i] = s1[i];
			i++;
		}
		str_heap[i] = '\0';
	}
	return (str_heap);
}
