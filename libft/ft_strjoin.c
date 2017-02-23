/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:18:04 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/20 13:11:19 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		m;
	char	*join;

	if ((s1 == 0) && (s2 == 0))
		return (NULL);
	else if ((s1 != NULL) && (s2 == NULL))
		return (ft_strdup(s1));
	else if ((s1 == NULL) && (s2 != NULL))
		return (ft_strdup(s2));
	else
	{
		n = ft_strlen(s1);
		m = ft_strlen(s2);
		if ((join = (char *)malloc(sizeof(char) * (n + m + 1))) == NULL)
			return (NULL);
		n = -1;
		while (s1[++n] != '\0')
			join[n] = s1[n];
		m = 0;
		while (s2[m] != '\0')
			join[n++] = s2[m++];
		join[n] = '\0';
	}
	return (join);
}
