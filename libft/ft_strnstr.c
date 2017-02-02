/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:32:18 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/29 17:50:35 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	j = 0;
	if (little[i] == '\0')
		return ((char *)big);
	while (j < len && big[j] != '\0')
	{
		k = j;
		while (big[j] == little[i] && big[j] != '\0' && (j < len))
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
