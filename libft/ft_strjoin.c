/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 12:18:04 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/02 19:53:07 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		n;
	int		m;
	char	*join;

	if ((s1 == 0) || (s2 == 0))
		return (NULL);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	if ((join = (char *)malloc(sizeof(char) * (n + m + 1))) == NULL)
		return (NULL);
	join[n + m] = '\0';
	n = 0;
	while (s1[n] != '\0')
	{
		join[n] = s1[n];
		n++;
	}
//	m = 0;

	/*ft_putstr("\x1b[34m");
	ft_putendl(s2);
	ft_putstr("\x1b[0m");*/
	n = n + m -1;
	while (m--)
	{
	//ft_putendl("coco56");
		join[n] = s2[m];
		n--;
	//	n++;
	//	m++;
	}
//	join[n] = '\0';
	return (join);
}
