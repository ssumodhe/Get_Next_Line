/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:27:56 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/26 16:12:46 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*t;
	int		i;

	if ((s == 0) || (f == 0))
		return (NULL);
	i = 0;
	while (s[i] != '\0')
		i++;
	if ((t = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
	{
		t[i] = f(s[i]);
		i++;
	}
	t[i] = '\0';
	return (t);
}
