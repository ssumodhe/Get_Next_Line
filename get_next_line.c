/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/12 15:24:38 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/17 16:59:45 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_gnl		*ft_fd_find_create(int	fd, t_gnl	**file)
{
	t_gnl	*tmp;
	t_gnl	*list;

	//	if (fd <= 2)
	//		return(-404); //error

	tmp = *file;
	//	(lstdel(file) ???)
	if(tmp)
	{
//		printf("YOP\n");
		//while (tmp != NULL)
		/*while (tmp->next != NULL)
		{
			list = tmp;
			if (fd == list->fd)
				return (list);
			tmp = tmp->next;
		}*/
		while (tmp && (tmp->fd != fd))
			tmp = tmp->next;

		/*if (tmp == NULL)
		{
			return (list);
		}
		printf("YOPilait\n");
		if (tmp->next == NULL)*/
		if (tmp == NULL)
		{
			tmp = *file;
			while (tmp->next != NULL)
				tmp = tmp->next;
			if ((list = (t_gnl *)malloc(sizeof(*list))) == NULL)
				return (NULL);
			list->fd = fd;
			list->stock = NULL;
			list->next = NULL;
			tmp->next = list;
			return (tmp->next);
		}
		else if (tmp->fd == fd)
			return (tmp);
	}
	else
	{
		if ((list = (t_gnl *)malloc(sizeof(*list))) == NULL)
			return (NULL);
		list->fd = fd;
		list->stock = NULL;
		list->next = NULL;
		*file = list;
		return (*file);
	}
	return (NULL);
}

int		ft_while_read(char *buff, char **line, char **stock)
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
//	printf(CYAN "Dans while_read --> Stock = %s\n" RESET, *stock);
		ft_strdel(stock);
		*stock = ft_strdup(ft_strchr(buff, '\n') + 1);
//	printf(CYAN "Dans while_read --> Stock = %s\n" RESET, *stock);
		if ((*stock)[0] == '\0')
			ft_strdel(stock);
			//*stock = NULL;
		return (1);
	}
	return (0);
}

int		ft_if_stock(char **stock, char **line)
{
	int		i;
	char 	*tmp;

//	printf(GREEN "Dans if_stock --> Stock = %s\n" RESET, *stock);
	if (!(*stock))
		return (0);
	if (ft_strchr(*stock, '\n') == NULL)
	{
//	printf(GREEN"Dans if_stock dans if--> Stock = %s\n" RESET, *stock);
		*line = ft_strdup(*stock);
		ft_strdel(stock);
		//*stock = NULL;
	}
	else
	{
//	printf(GREEN"Dans if_stock dans else --> Stock = %s\n" RESET, *stock);
		i = 0;
		while ((*stock)[i] != '\n')
			i++;
		*line = ft_strsub(*stock, 0, i);
		tmp = *stock;
		*stock = ft_strdup(ft_strchr(tmp, '\n') + 1);
		ft_strdel(&tmp);
		if ((*stock)[0] == '\0')
			//*stock = NULL;
			ft_strdel(stock);
		return (1);
	}
	return (0);
}

/*void	ft_putlist(t_gnl *list)
{
	while (list)
	{
		ft_putstr("fd = ");
		ft_putnbr(list->fd);
		ft_putstr(" | stock  = ");
		ft_putendl(list->stock);
		ft_putstr("\n");
		list = list->next;
	}
}*/

int		get_next_line(const int fd, char **line)
{
	int			octet;
	char		buff[BUFF_SIZE + 1];
//	static char	*stock;
	static t_gnl	*file;
	t_gnl			*tmp_file;

	if (fd < 0 || !line)
		return (-1);
//	ft_putstr("LIST :\n");
//	ft_putlist(file);
	*line = NULL;
	tmp_file = ft_fd_find_create(fd, &file);
//	printf("FD de la liste = %d\n", file->fd);
//	printf("STOCK de la liste = %s\n" RESET, file->stock);
//	printf("STOCK  = %s\n" RESET, stock);
	if (ft_if_stock(&tmp_file->stock, line) == 1)
		return (1);
//	if (!(buff = ft_strnew(BUFF_SIZE)))
//		return (-1);
	while ((octet = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (octet < 0)
		{
	//		ft_strdel(&buff);
			return (-1);
		}
		buff[octet] = '\0';
//	printf(RED"read --> Buff = %s\n" RESET, buff);
		if (ft_while_read(buff, line, &tmp_file->stock) == 1)
		{
//			printf(RED"read --> Stock = %s\n" RESET, file->stock);
	//		stock = ft_strdup(file->stock);
	//		ft_strdel(&buff);
			return (1);
		}
	}
	if (*line != NULL)
	{
		//ft_strdel(&buff);
		return (1);
	}
	//ft_strdel(&buff);
	return (0);
}
