/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:33:29 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/16 17:22:08 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd_1;
	int		fd_2;
	int		fd_3;
	int		ret = 0;
	char	*line;
	int		count;

	if (argc != 4)
	{
		printf(RED"error : mauvais nombre d'arguments\n"RESET);
		return (0);
	}
	if	((fd_1 = open(argv[1], O_RDWR)) < 0)
	{
		printf(RED"open : fail\n"RESET);
		return (0);
	}
	if	((fd_2 = open(argv[2], O_RDWR)) < 0)
	{
		printf(RED"open : fail\n"RESET);
		return (0);
	}
	if	((fd_3 = open(argv[3], O_RDWR)) < 0)
	{
		printf(RED"open : fail\n"RESET);
		return (0);
	}
	line = NULL;


	count = 0;
	while (count <= 1)
	{
		ret = get_next_line(fd_1, &line);
		ft_putstr(HIGHLIGHT GREEN);
		ft_putendl(line);
		ft_putstr(RESET);
		count++;
	}
	while (count <= 3)
	{
		ret = get_next_line(fd_2, &line);
		ft_putstr(HIGHLIGHT YELLOW);
		ft_putendl(line);
		ft_putstr(RESET);
		count++;
	}
	while (count <= 5)
	{
		ret = get_next_line(fd_3, &line);
		ft_putstr(HIGHLIGHT CYAN);
		ft_putendl(line);
		ft_putstr(RESET);
		count++;
	}

/*
	(void)count;
	while ((ret = get_next_line(fd_1, &line)) == 1)
	{
		ft_putstr(YELLOW);
		ft_putendl(line);
		ft_putstr(RESET);
	}*/

	if (close(fd_1) < 0)
	{
		printf(RED"close fd_1 : fail\n"RESET);
		return (0);
	}
	if (close(fd_2) < 0)
	{
		printf(RED"close fd_2 : fail\n"RESET);
		return (0);
	}

	return (0);
}
