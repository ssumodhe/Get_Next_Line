/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:10:54 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/22 18:53:56 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*cast_src;
	unsigned char			*cast_dst;
	unsigned char			cast_c;
	size_t					i;

	cast_src = (unsigned char *)src;
	cast_dst = (unsigned char *)dst;
	cast_c = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		cast_dst[i] = cast_src[i];
		if (cast_src[i] == cast_c)
			return (cast_dst + (i + 1));
		i++;
	}
	cast_dst = NULL;
	return (cast_dst);
}
