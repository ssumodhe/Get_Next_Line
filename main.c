/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 19:33:29 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/17 19:20:22 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret = 0;
//	int		a = 0;
	char	*line;
	int		nombre;

	if (argc != 2)
	{
		printf(RED"error : mauvais nombre d'arguments\n"RESET);
		return (0);
	}
	if	((fd = open(argv[1], O_RDWR)) < 0)
	{
		printf(RED"open : fail\n"RESET);
		return (0);
	}
	line = NULL;
/*	if (get_next_line(fd, &line) == 1)
	{
		printf("END\n");
		printf("MAIN | Line : %s\n", line);
	}
	else		
		printf("return != 1\n");*/

	nombre = 1;
	//while (get_next_line(fd, &line) == 1)
	while ((ret = get_next_line(fd, &line)) == 1)
	{
/*		ft_putstr(YELLOW);
		ft_putstr("MAIN | ret = ");
		ft_putnbr(ret);
		ft_putendl("");*/
	//	printf(YELLOW"MAIN | Line : \n"RED"<\""RESET"%s"RED"\">\n\n"RESET, line);
	//	printf(YELLOW"MAIN | Return : %d\n\n"RESET, ret);
//		ft_putstr(YELLOW);

		//ft_putnbr(nombre);
		//ft_putchar(' ');
/*		ft_putstr("Line = ");
		ft_putstr(RED);
		ft_putstr("<");
		ft_putstr(YELLOW);*/
		ft_putstr(line);
//		ft_putstr(RED);
/*		ft_putstr(">");
		ft_putendl("");*/
		//ft_putnbr(ft_strlen(line));
		//ft_putendl("");
//		ft_putstr(RESET);
		//if (ft_strlen(line) != 64)
		//	break ;
		ft_strdel(&line);
		//nombre++;
	}

//	while(1);

/*	ft_putstr("------------------------\n");
	ft_putstr(YELLOW);
	ft_putendl("MAIN | THE END");
	ft_putstr(RESET);
	ft_putnbr(ret);
	ft_putendl("");
	//ft_putstr(YELLOW);
	ft_putendl(line);*/
	//ft_putstr(RESET);
//	printf(YELLOW"MAIN | THE END Line : %s\n\n"RESET, line);
//	printf(YELLOW"MAIN | Return : %d\n\n"RESET, ret);


/*	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);
	ret = get_next_line(fd, &line);
	a++;
	printf("%d) ret = %d\n", a, ret);
		printf(YELLOW"MAIN | Line : %s\n\n"RESET, line);*/
	if (close(fd) < 0)
	{
		printf(RED"close : fail\n"RESET);
		return (0);
	}
	return (0);
}

//check testfile clem
//1ret
//2lignes_1videfin
//2ret (pb \n fin de fichier)
