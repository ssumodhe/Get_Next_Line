/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 19:14:37 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/22 18:48:12 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	cast_c;
	unsigned char	*cast_s;

	cast_c = (unsigned char)c;
	cast_s = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (cast_s[i] == cast_c)
			return (cast_s + i);
		i++;
	}
	return (NULL);
}
