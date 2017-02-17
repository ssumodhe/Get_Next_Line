/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:24:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/17 19:21:19 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** check les cat -e des renuds... 
*/

t_gnl		*ft_fill_in_list(int	fd)
{
	t_gnl	*list;

	if ((list = (t_gnl *)malloc(sizeof(*list))) == NULL)
			return (NULL);
	list->fd = fd;
	list->stock = NULL;
	list->next = NULL;
	return (list);
}

t_gnl		*ft_fd_find_create(int	fd, t_gnl	**file)
{
	t_gnl	*tmp;

	tmp = *file;
	if (tmp)
	{
		while (tmp && (tmp->fd != fd))
			tmp = tmp->next;
		if (tmp == NULL)
		{
			tmp = *file;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = ft_fill_in_list(fd);
			return (tmp->next);
		}
		else if (tmp->fd == fd)
			return (tmp);
	}
	else
	{
		*file = ft_fill_in_list(fd);
		return (*file);
	}
	return (NULL);
}

int		ft_while_read(char *buff, char **line, char **stock)
{
	int		i;
	char	*tmp;
	char	*tmp_sub;

	if (ft_strchr(buff, '\n') != NULL)
	{
		i = 0;
		while (buff[i] != '\n')
			i++;
		tmp_sub = ft_strsub(buff, 0, i);
		tmp = *line;
		*line = ft_strjoin(tmp, tmp_sub);
		ft_strdel(&tmp);
		ft_strdel(&tmp_sub);
		ft_strdel(stock);
		*stock = ft_strdup(ft_strchr(buff, '\n') + 1);
		if ((*stock)[0] == '\0')
			ft_strdel(stock);
		return (1);
	}
	tmp = *line;
	*line = ft_strjoin(tmp, buff);
	ft_strdel(&tmp);
	return (0);
}




/*int		ft_while_read(char *buff, char **line, char **stock)
  {
  int		i;
  char	*tmp;
  char	*tmp_2;

  if (ft_strchr(buff, '\n') == NULL)
  {
  if (*line)
  {
  tmp = *line;
 *line = ft_strjoin(tmp, buff);
 ft_strdel(&tmp);
 }
 else
 *line = ft_strdup(buff);
 }
 else
 {
 i = 0;
 while (buff[i] != '\n')
 i++;
 if (*line)
 {
 tmp = *line;
 tmp_2 = ft_strsub(buff, 0, i);
 *line = ft_strjoin(tmp, tmp_2);
 ft_strdel(&tmp);
 ft_strdel(&tmp_2);
 }
 else
 {
 tmp = ft_strsub(buff, 0, i);
 *line = ft_strdup(tmp);
 ft_strdel(&tmp);
 }
 ft_strdel(stock);
 *stock = ft_strdup(ft_strchr(buff, '\n') + 1);
 if ((*stock)[0] == '\0')
 ft_strdel(stock);
 return (1);
 }
 return (0);
 }*/

int		ft_if_stock(char **stock, char **line)
{
	int		i;
	char 	*tmp;

	if (!(*stock))
		return (0);
	if (ft_strchr(*stock, '\n') == NULL)
	{
		*line = ft_strdup(*stock);
		ft_strdel(stock);
	}
	else
	{
		i = 0;
		while ((*stock)[i] != '\n')
			i++;
		*line = ft_strsub(*stock, 0, i);
		tmp = *stock;
		*stock = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
		if ((*stock)[0] == '\0')
			ft_strdel(stock);
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int				octet;
	char			buff[BUFF_SIZE + 1];
	t_gnl			*tmp_file;
	static t_gnl	*file;

	if (fd < 0 || !line || BUFF_SIZE < 0)
		return (-1);
	*line = NULL;
	tmp_file = ft_fd_find_create(fd, &file);
	if (ft_if_stock(&tmp_file->stock, line) == 1)
		return (1);
	while ((octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (octet < 0)
			return (-1);
		buff[octet] = '\0';
		if (ft_while_read(buff, line, &tmp_file->stock) == 1)
			return (1);
	}
	if (*line != NULL)
		return (1);
	return (0);
}
