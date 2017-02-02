/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:26:06 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/25 19:14:21 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cast_src;
	unsigned char	*cast_dst;

	cast_src = (unsigned char *)src;
	cast_dst = (unsigned char *)dst;
	if (src < dst)
	{
		cast_src = cast_src + len - 1;
		cast_dst = cast_dst + len - 1;
		while (len--)
			*cast_dst-- = *cast_src--;
	}
	else
		while (len)
		{
			*cast_dst = *cast_src;
			cast_dst++;
			cast_src++;
			len--;
		}
	return (dst);
}
