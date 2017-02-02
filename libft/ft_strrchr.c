/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:16:50 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/21 09:41:34 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cast_c;
	char	*cast_s;
	int		n;

	cast_c = (char)c;
	cast_s = (char *)s;
	n = 0;
	while (cast_s[n] != '\0')
		n++;
	while (n != -1)
	{
		if (cast_s[n] == cast_c)
		{
			return (cast_s + n);
		}
		n--;
	}
	return (0);
}
