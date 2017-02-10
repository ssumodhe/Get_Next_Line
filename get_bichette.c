/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bichette.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:47:40 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/10 19:06:39 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_if_stock(char **stock, char **line)
{
	int		i;

	if (!(*stock) && stock[0] == '\0')
		return (0);
	i = 0;
	if (ft_strchr(*stock, '\n') == NULL)
	{
		*line = ft_strdup(*stock);
		(*stock) = NULL;
	}
	else
	{
		while ((*stock)[i] != '\n')
			i++;
		*line = ft_strsub(*stock, 0, i);
		*stock = ft_strdup(ft_strchr(*stock, '\n') + 1);
		if ((*stock)[0] == '\0')
			*stock = NULL;
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			octet;
	char		*buff;
	static char	*stock;
	int			i;

	if (fd < 0 || !line)
		return (-1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	*line = NULL;

	if (ft_if_stock(&stock, line) == 1)
		return (1);

	while ((octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (octet < 0)
			return (-1);
		buff[octet] = '\0';

		if (ft_strchr(buff, '\n') == NULL) //pas de '\n'
		{
			if (*line)
				*line = ft_strjoin(*line, buff);
			else
				*line = ft_strdup(buff);
		}
		else // '\n'
		{
			i = 0;
			while (buff && buff[i] != '\n')
				i++;
			*line = ft_strjoin(*line, ft_strsub(buff, 0, i));
			stock = ft_strdup(ft_strchr(buff, '\n') + 1);
			if (stock[0] == '\0')
				stock = NULL;
			return (1);
		}
			
	}

	if (*line != NULL)
		return (1);
	
	return (0);
}
