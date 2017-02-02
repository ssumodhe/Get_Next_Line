/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:01:05 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/18 17:15:18 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	char					*desti;
	const char				*source;

	source = (const char *)src;
	desti = (char *)dst;
	i = 0;
	while (i < n)
	{
		desti[i] = source[i];
		i++;
	}
	return (dst);
}
