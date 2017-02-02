/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:12:30 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/18 17:19:57 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	d;
	unsigned char	*a;
	size_t			i;

	d = (unsigned char)c;
	a = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		a[i] = d;
		i++;
	}
	return (b);
}
