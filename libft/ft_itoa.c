/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:34:18 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/22 19:49:56 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	int				i;
	int				n_int;

	n_int = ft_intlen(n);
	if ((s = (char *)malloc(sizeof(char) * (n_int + 1))) == NULL)
		return (NULL);
	s[n_int] = '\0';
	i = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		n = n * -1;
		s[i++] = '-';
	}
	if (n == 0)
		s[--n_int] = '0';
	while (n > 0)
	{
		s[--n_int] = ('0' + (n % 10));
		n = n / 10;
	}
	return (s);
}
