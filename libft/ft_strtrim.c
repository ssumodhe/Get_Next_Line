/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 13:50:15 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/26 19:33:57 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trim;

	if (s == 0)
		return (NULL);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && (s[i] != '\0'))
		i++;
	if (i == ft_strlen(s))
		return (ft_strdup("\0"));
	start = i;
	i = 0;
	while (s[i] != '\0')
		i++;
	i--;
	while (i && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i--;
	end = i;
	trim = ft_strsub(s, start, (end - start + 1));
	return (trim);
}
