/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/27 15:27:29 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** /!\ Ma variable statique est une structure composee de deux variables
 ** Boucle while sur le read pour lire jusqu'a la fin du fichier (evite leaks);
 ** mais ne colle pas la fin du ligne a sa suite nouvellement lu par read
 */

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
	int			i;
	int			j;
	int			octet;
	char		*tmp;
	char		*buff_stock;
	char		*buff_start;
	char		buff[BUFF_SIZE + 1];
	static char *Clem = NULL;

	i = 0;
	tmp = NULL;
	*line = NULL;
	buff_start = NULL;
	buff_stock = NULL;
	if (Clem != NULL)
	{
		buff_stock = ft_strdup(Clem);
	//	printf("Clem = \"%s\"\n", Clem);
	//ICI : Check que pas plusieurs lignes dans Clem
	}
	while ((octet = (read(fd, buff, BUFF_SIZE))) != 0)
	{
		buff[octet] = '\0';
		if (ft_analysis(buff) == 0)
		{
			if (buff_stock)
				tmp = ft_strdup(buff_stock);
			if (!tmp)
				buff_stock = ft_strdup(buff);
			else
				buff_stock = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
		else if (ft_analysis(buff) == 1)
		{
			while (buff[i] != '\n')
				i++;
			if ((buff_start = (char *)malloc(sizeof(char) * i)) == NULL)
				return (-1);
			i = 0;
			while (buff[i] != '\n')
			{
				buff_start[i] = buff[i];
				i++;
			}
			buff_start[i] = '\0';
		//	printf("buff_start = \"%s\"\n", buff_start);
		//	printf("buff_stock = \"%s\"\n", buff_stock);
			if (buff_stock)
			{
				j = 0;
				while (ft_isspace(buff_stock[j]) == 1)
					j++;
				if (buff_stock[j] == '\0')
					ft_strdel(&buff_stock);
			}
			if (buff_stock != NULL)
			{
				(*line) = ft_strjoin(buff_stock, buff_start);
			//	printf(" 1 Line = \"%s\"\n", *line);
			}
			else if (buff_stock == NULL)
			{
				if (buff_start)
				{
					j = 0;
					while (ft_isspace(buff_start[j]) == 1)
						j++;
					if (buff_start[j] == '\0')
						ft_strdel(&buff_start);
				}
				if (buff_start != NULL)
					(*line) = ft_strdup(buff_start);
			//	printf(" 2 Line = \"%s\"\n", *line);
			}
			ft_strdel(&buff_stock);
			while (ft_isspace(buff[i]) == 1)
					i++;
			if (buff[i] != '\0')
				Clem = ft_strdup(&buff[i]);
//			printf("Clem = \"%s\"\n", Clem);
			return (1);
		}
	}
	if (Clem != NULL)  //Si qqchose dans line/buff_stock, l'envoyer avant la fin du programme
	{
		(*line) = ft_strdup(Clem); //ICI : ATTENTION SI PLUSIEURS \n DANS CLEM!
		Clem = NULL;
		return (1);
	}
	return (0);
}





//		printf("GNL | Clem != NULL\n");
//		printf("Clem = \"%s\"\n", Var.Clem);

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
 **read.
 **char	*tmp;
 **
 **while (read(fd, buff, BUFF_SIZE) != 0)
 **{
 **	tmp = buff_stock;
 **	buff_stock = ft_strjoin(tmp, buff);
 **	ft_strdel(&tmp);
 **}
 **
 */
