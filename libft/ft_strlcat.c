/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:03:37 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/21 09:35:15 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	s_i;
	size_t	s_j;

	i = 0;
	j = 0;
	while (dst[i] != '\0')
		i++;
	s_i = i;
	while (src[j] != '\0')
		j++;
	s_j = j;
	if (n > i)
	{
		j = 0;
		while ((i < (n - 1)) && (src[j] != '\0'))
			dst[i++] = src[j++];
		dst[i] = '\0';
		return (s_i + s_j);
	}
	else
		return (n + s_j);
}
