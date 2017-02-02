/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:31:06 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/22 17:34:28 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (big[j] != '\0')
	{
		k = j;
		while (big[j] == little[i] && big[j] != '\0')
		{
			i++;
			j++;
			if (little[i] == '\0')
				return ((char *)big + k);
		}
		j = k;
		i = 0;
		j++;
	}
	return (NULL);
}
