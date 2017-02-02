/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:02:06 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/22 17:57:13 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cast_c;
	char	*cast_s;
	int		i;

	cast_c = (char)c;
	cast_s = (char *)s;
	i = 0;
	while (cast_s[i] != '\0')
	{
		if (cast_s[i] == cast_c)
			return (cast_s + i);
		i++;
	}
	if (cast_s[i] == '\0' && cast_s[i] == cast_c)
		return (cast_s + i);
	return (0);
}
