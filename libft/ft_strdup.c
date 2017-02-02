/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 13:30:13 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/02 17:00:20 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cpy;
	int		n;

	n = 0;
	while (src[n] != '\0')
		n++;
	if ((cpy = (char *)malloc(sizeof(char) * (n + 1))) == NULL)
		return (NULL);
	cpy[n] = '\0';
	while (n--)
	{
		cpy[n] = src[n];
	}
	return (cpy);
}
