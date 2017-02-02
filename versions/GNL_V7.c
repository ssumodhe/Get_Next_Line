/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/31 14:08:50 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** /!\ Ma variable statique est une structure composee de deux variables
 ** Boucle while sur le read pour lire jusqu'a la fin du fichier (evite leaks);
 ** mais ne colle pas la fin du ligne a sa suite nouvellement lu par read
 */

/*
** Ne place pas le dernier Clem, et le reset a NULL Surement Clem = buffstock pas pris en compte dans 2ieme boucle
** (quand buffanalysis = 1)
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

	tmp = NULL;
	*line = NULL;
	buff_start = NULL;
	buff_stock = NULL;
	if (Clem != NULL)
	{
		buff_stock = ft_strdup(Clem);
		ft_strdel(&Clem);
//		printf(GREEN "Clem = \"%s\"\n" RESET, Clem);
	//ICI : Check que pas plusieurs lignes dans Clem
	}
	while ((octet = (read(fd, buff, BUFF_SIZE))) != 0)
	{
		buff[octet] = '\0';
		if (ft_analysis(buff) == 0)
		{
//			printf(PURPLE "GNL | Buff n'a pas de \\n\n" RESET);
//			printf("GNL | Read a lu buff :\"%s\"\n", buff);
			if (buff_stock)
				tmp = ft_strdup(buff_stock);
			if (!tmp)
				buff_stock = ft_strdup(buff);
			else
				buff_stock = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
//			printf("GNL | Buff_stock :\"%s\"\n", buff_stock);
		}
		else if (ft_analysis(buff) == 1)
		{
			i = 0;
//			printf(PURPLE "GNL | Buff a au moins un \\n\n" RESET);
//			printf("GNL | Read a lu buff :\"%s\"\n", buff);
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
//			if (buff_start[0] == '\0')
//				ft_strdel(&buff_start);
//			printf("GNL | buff_stock = \"%s\"\n", buff_stock);
//			printf("GNL | buff_start = \"%s\"\n", buff_start);
			/*if (buff_stock)
			{
				j = 0;
				while (ft_isspace(buff_stock[j]) == 1)
					j++;
				if (buff_stock[j] == '\0')
					ft_strdel(&buff_stock);
			}*/
			if (buff_stock != NULL)
			{
				(*line) = ft_strjoin(buff_stock, buff_start);
			//	printf(" 1 Line = \"%s\"\n", *line);
			}
			else if (buff_stock == NULL && Clem == NULL)
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
			else if (buff_stock == NULL && Clem != NULL)
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
				{
					(*line) = ft_strjoin(Clem, buff_start);
					ft_strdel(&Clem);
				}
			//	printf(" 3 Line = \"%s\"\n", *line);
			}
			ft_strdel(&buff_stock);
			while (ft_isspace(buff[i]) == 1)
				i++;
			if (buff[i] != '\0')
				Clem = ft_strdup(&buff[i]);
		//	printf("GNL | Clem = \"%s\"\n", Clem);
			if ((*line) != NULL)
				return (1);
		}
	}
	if (Clem != NULL)  //Si qqchose dans line/buff_stock, l'envoyer avant la fin du programme
	{
		(*line) = ft_strdup(Clem); //ICI : ATTENTION SI PLUSIEURS \n DANS CLEM!
//		printf("GNL | Last line : %s\n", *line);
		Clem = NULL;
		return (1);
	}
	if (buff_stock != NULL)  //Si qqchose dans line/buff_stock, l'envoyer avant la fin du programme
	{
		(*line) = ft_strdup(buff_stock); //ICI : ATTENTION SI PLUSIEURS \n DANS CLEM!
//		printf("GNL | Last line buffstock : %s\n", *line);
		buff_stock = NULL;
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



