/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:33:22 by ssumodhe          #+#    #+#             */
/*   Updated: 2016/11/26 16:17:38 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_letters(char const *s, int i, char c)
{
	int		n;

	n = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		n++;
		i++;
	}
	n--;
	return (n);
}

static char			**ft_fill_it(char **tab, char const *s, char c, int n_words)
{
	int		i;
	int		j;
	int		n;
	int		n_letters;

	i = 0;
	n = 0;
	while (i < n_words)
	{
		n_letters = ft_count_letters(s, i, c);
		if ((tab[i] = (char *)malloc(sizeof(char) * (n_letters + 1))) == NULL)
			return (NULL);
		j = 0;
		while (s[n] == c && s[n] != '\0')
			n++;
		while (s[n] != c && s[n] != '\0')
		{
			tab[i][j] = s[n];
			j++;
			n++;
		}
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}

static int			ft_count_words(char const *s, char c)
{
	int		i;
	int		n;

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			n++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (n);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		n_words;

	if (s == 0)
		return (NULL);
	n_words = ft_count_words(s, c);
	if ((tab = (char **)malloc(sizeof(char *) * (n_words + 1))) == NULL)
		return (NULL);
	tab = ft_fill_it(tab, s, c, n_words);
	return (tab);
}
