/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:24:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/15 18:34:51 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_while_read(char *buff, char **line, char **stock)
{
	int		i;

	if (ft_strchr(buff, '\n') == NULL)
	{
		if (*line)
			*line = ft_strjoin(*line, buff);
		else
			*line = ft_strdup(buff);
	}
	else
	{
		i = 0;
		while (buff[i] != '\n')
			i++;
		if (*line)
			*line = ft_strjoin(*line, ft_strsub(buff, 0, i));
		else
			*line = ft_strdup(ft_strsub(buff, 0, i));
		*stock = ft_strdup(ft_strchr(buff, '\n') + 1);
		if ((*stock)[0] == '\0')
			*stock = NULL;
		return (1);
	}
	return (0);
}

int		ft_if_stock(char **stock, char **line)
{
	int		i;

	if (!(*stock) && stock[0] == '\0')
		return (0);
	if (ft_strchr(*stock, '\n') == NULL)
	{
		*line = ft_strdup(*stock);
		(*stock) = NULL;
	}
	else
	{
		i = 0;
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

	if (fd < 0 || !line)
		return (-1);
	*line = NULL;
	if (ft_if_stock(&stock, line) == 1)
		return (1);
	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (octet < 0)
			return (-1);
		buff[octet] = '\0';
		if (ft_while_read(buff, line, &stock) == 1)
			return (1);
	}
	if (*line != NULL)
		return (1);
	return (0);
}
