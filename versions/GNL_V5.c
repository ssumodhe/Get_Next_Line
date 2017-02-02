/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/25 11:25:38 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
 ** /!\ Variable statique est une structure composee de deux variables
 ** Fonctionne pour lire jusqu'a la fin du fichier
 ** mais ne colle pas la fin du ligne a sa suite nouvellement lu par read
 */

char	*ft_buff_analysis(char *buff, char **line, t_GNL Var)
{
	int		i;
	int		a;
	char	c;
	char	*whatsleft;

	whatsleft = NULL;
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
//	printf(PURPLE "BA | J'ai la taille de la ligne\n" RESET);
	c = buff[i];
//	printf(PURPLE "BA | J'ai la terminaison de la ligne\n" RESET);
	if (c != '\0')
	{
		printf("le rest est : \"%s\"\n", Var.Join);
		a = 0;
		if (Var.Join != NULL)
		{
			//printf(PURPLE "BA | Il me restait un bout de ligne\n" RESET);
			a = ft_strlen(Var.Join);
			//free line before?
			if ((*line = (char *)malloc(sizeof(char) * (a + i))) == NULL)
				return (NULL);
			//		(*line) = ft_strdup(Var.Join);
			a = 0;
			while (Var.Join[a] != '\0')
			{
				(*line)[a] = Var.Join[a];
				a++;
			}
			a--;
			//free Var.Join?
			Var.Join = NULL;
			printf(RED HIGHLIGHT "\tline so far :\" %s\"\n" RESET, *line);
		}
		else
		{
//			printf(PURPLE "BA | Pas de bout de ligne\n" RESET);
			//free line before?
			if ((*line = (char *)malloc(sizeof(char) * i)) == NULL)
				return (NULL);
		}
		i = 0;
		while (buff[i] != c)
		{
			(*line)[a] = buff[i];
			a++;
			i++;
		}
//		printf(PURPLE "BA | Buff est correctement copie dans Line\n" RESET);
		(*line)[a] = '\0';
		i++;
		whatsleft = ft_strdup(buff + i);
	}
	else if (c == '\0')
	{
		//free Var.Join?
		if ((Var.Join = (char *)malloc(sizeof(char) * i)) == NULL)
			return (NULL);
		i = 0;
		while (buff[i] != '\0')
		{
			Var.Join[i] = buff[i];
			i++;
		}
		Var.Join[i] = '\0';
		//Var.Join = ft_strdup(buff + i);
//		printf("BA | J'ai un reste !!!\n");
		printf("le rest ici est : \"%s\"\n", Var.Join);
	}
	printf("BA | Line :\n\"%s\"\n", *line);
	printf(CYAN"BA | Rest :\n\"%s\"\n"RESET, whatsleft);
	return (whatsleft);
}

int		get_next_line(const int fd, char **line)
{
	int		octet;
	char	buff[BUFF_SIZE];	
	//	static char *Clem = NULL;
	static t_GNL	Var = {NULL, NULL};

	*line = NULL;
	if (Var.Clem == NULL)
	{
		printf("GNL | Clem == NULL\n");
		octet = read(fd, buff, BUFF_SIZE);
		if (octet == 0)
			return (0);
		Var.Clem = ft_buff_analysis(buff, line, Var);
	//	if (Var.Join != NULL)
	//		printf("GNL | Var.Join : 
		return (1);
	}
	else if (Var.Clem != NULL)
	{
		printf("GNL | Clem != NULL\n");
		printf("Clem = \"%s\"\n", Var.Clem);
		Var.Clem = ft_buff_analysis(Var.Clem, line, Var);
		return (1);
	}
	/*
	 ** tester avec une structure static? char *Clem + char *Join
	 ** tester de virer Var.Clem dans les retour de GNL e le remplacer par line (pour eviter les retour null entre chaque read.
	 */
	return (0);
}

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
