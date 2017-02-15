/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/09 20:39:16 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** ATTENTION :
 ** - A la derniere ligne (a la sortie de la boucle sur le read)
 ** - Au fd recupere
 ** - Dans la boucle du read, si octet est < 0 : return (-1)
 ** - S'il reste plus d'une ligne dans Clem (a tester avec differents BUFF_SIZE - grand de preference)
 */

/*
 ** Segfault dans ft_dup_join pb 
 **
 */

char	*ft_start(char *buff_1, t_GNL *truc)
{
	char	*start;
	int		i;

	start = NULL;
	printf(RED"Start = %s\n"RESET, start);
	i = 0;
	while (buff_1[i] != '\n' && buff_1[i] != '\0')
		i++;
	if ((start = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (buff_1[i] != '\n')
	{
		start[i] = buff_1[i];
		i++;
	}
	start[i] = '\0';
	printf(RED"Start = %s\n", start);
	if (buff_1[i + 1])
		truc->clem = ft_strdup(&buff_1[i + 1]);
	ft_strdel(&buff_1);
	return (start);
}

char	*ft_dup_join(char *buff_1, char *buff_2, int a)
{
	char	*tmp;
	char	*stock;

	stock = NULL;
	tmp = NULL;
	printf(CYAN"buff_1 = %s\n"RESET, buff_1);
	printf(CYAN"buff_2 = %s\n"RESET, buff_2);
	printf(CYAN"     a = %d\n"RESET, a);
/*	if (buff_1)
	{
		tmp = ft_strdup(buff_1);
		printf(CYAN"   tmp = %s\n"RESET, tmp);
	}*/
	if (buff_1 && a == 0)
	{
		printf(CYAN"   stock = %s\n"RESET, stock);
		printf(CYAN"buff_2 = %s\n"RESET, buff_2);
		stock = ft_strjoin(buff_1, buff_2);
		printf(CYAN"   stock = %s\n"RESET, stock);
	}
	else if (buff_1 && a == 1)
	{
		stock = ft_strjoin(buff_2, buff_1);
	}
	else if (buff_1 && a == 2)
	{
		stock = ft_strdup(buff_1);
	}
	else if (!buff_1)
	{
		printf(CYAN"ici   stock = %s\n"RESET, stock);
		stock = ft_strdup(buff_2);
		printf(CYAN"ici   stock = %s\n"RESET, stock);
	}
	ft_strdel(&buff_1);
	ft_strdel(&buff_2);
	printf(CYAN"buff_2 = %s\n"RESET, buff_2);
	ft_strdel(&tmp);
	printf(CYAN"   tmp = %s\n"RESET, tmp);
	return (stock);
}

int		ft_analysis(char *buff)
{
	int		i;
	char	c;

	if (!buff)
		return (-1);
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	c = buff[i];
	if (c == '\n')
	{
		return (1);
	}
	else if (c == '\0')
	{
		return (0);
	}
	return (-1);
}

int		get_next_line(const int fd, char **line)
{
	int				octet;
	char			*buff_stock;
	char			*buff_start;
	char			*buff;
	static t_GNL	truc = {NULL};

	if (fd < 0 || line == NULL)
		return (-1);

	if ((buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	*line = NULL;
	buff_stock = NULL;
	buff_start = NULL;

	if (truc.clem != NULL)
	{
		buff_stock = ft_dup_join(buff_stock, truc.clem, 1);
		if (ft_analysis(buff_stock) == 1)
		{
			buff_start = ft_start(buff_stock, &truc);
			(*line) = ft_strdup(buff_start);
			//	ft_strdel(&buff_start);
			//	ft_strdel(&truc.clem);
			return (1);
		}
		else
			ft_strdel(&buff_stock);
		//	ft_strdel(&truc.clem);
	}


	if (buff_stock && buff_stock[0] == '\n')
	{
		if (((*line) = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
		(*line)[0] = '\0';
		if (buff_stock[1]) // && buff_stock[1] != '\0' ??
			truc.clem = strdup(&buff_stock[1]);
		//ft_strdel(&buff_stock);
		return (1);
	}


	while ((octet = (read(fd, buff, BUFF_SIZE))) != 0)
	{
		if (octet < 0)
			return (-1);

		buff[octet] = '\0';

		if (ft_analysis(buff) == 0)
		{
			printf(GREEN"A = 0 Buff = %s\n"RESET, buff);
			buff_stock = ft_dup_join(buff_stock, buff, 0);
			printf(GREEN"A = 0 Stock = %s\n"RESET, buff_stock);
			printf(GREEN"A = 0 Clem = %s\n"RESET, truc.clem);
			printf(GREEN"--------------------------\n"RESET);
		}
		else if (ft_analysis(buff) == 1)
		{
			printf(PURPLE"A = 1 Buff = %s\n"RESET, buff);
			printf(GREEN"A = 1 Clem = %s\n"RESET, truc.clem);
			buff_start = ft_start(buff, &truc);
			(*line) = ft_dup_join(buff_stock, buff_start, 0);
			//ft_strdel(&buff_start);
			return (1);
		}
	}


	if (buff_stock != NULL)
	{
		if (ft_analysis(buff_stock) == 0)
		{
			(*line) = ft_dup_join(buff_stock, NULL, 2);
			return (1);
		}

		if (ft_analysis(buff_stock) == 1)
		{
			buff_start = ft_start(buff_stock, &truc);
			(*line) = ft_strdup(buff_start);
			//ft_strdel(&buff_start);
			return (1);
		}
	}

	return (0);
}



/*
 ** tester avec une structure static? char *Clem + char *Join
 ** tester de virer Var.Clem dans les retour de GNL e le remplacer par line 
 ** 						(pour eviter les retour null entre chaque read.
 ** tester remplacer buff_stock par line (/!\ pas de return avec le prochain '\n')
 **							du coup utiliser strcat pour remplir line.
 */

/*
 ** return (1) --> la ligne a ete lue
 ** return (0) --> la lecture est terminee
 ** return (-1)--> erreur
 */


/*
 **read - eviter les leaks.
 **char	*tmp;
 **
 **while (read(fd, buff, BUFF_SIZE) != 0)
 **{
 **	tmp = buff_stock;
 **	buff_stock = ft_strjoin(tmp, buff);
 **	ft_strdel(&tmp);
 **}
 */



