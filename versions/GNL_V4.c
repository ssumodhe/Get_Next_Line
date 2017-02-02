/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/24 17:09:58 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** Fonctionne pour lire jusqu'a la fin du fichier
** mais ne colle pas la fin du ligne a sa suite nouvellement lu par read
*/

char	*ft_buff_analysis(char *buff, char **line)
{
	int		i;
	char	c;
	char	*whatsleft;

	whatsleft = NULL;
	i = 0;
	while (buff[i] != '\0' && buff[i] != '\n')
		i++;
	c = buff[i]; //je stock si c'est un \n ou \0 a reprendre apres pour le EOF return whatsleft = NULL
	if ((*line = (char *)malloc(sizeof(char) * i)) == NULL)
		return (NULL);
	i = 0;
	while (buff[i] != c)
	{
		(*line)[i] = buff[i];
		i++;
	}
	(*line)[i++] = '\0';
	if (c != '\0')
		whatsleft = ft_strdup(buff + i);
//	if (c == '\0')
//		whatsleft = // a traiter avec strjoin car debut de la ligne que va lire read apres;
	printf("BA | Line :\n\"%s\"\n", *line);
	printf(CYAN"BA | Rest :\n\"%s\"\n"RESET, whatsleft);
	return (whatsleft);
}

int		get_next_line(const int fd, char **line)
{
	int		octet;
	char	buff[BUFF_SIZE];	
	static char *Clem = NULL;

	*line = NULL;
	if (Clem == NULL)
	{
		octet = read(fd, buff, BUFF_SIZE);
		if (octet == 0)
			return (0);
		Clem = ft_buff_analysis(buff, line);
		return (1);
	}
	else if (Clem != NULL)
	{
		Clem = ft_buff_analysis(Clem, line);
		return (1);
	}
/*
** tester avec une structure static? char *Clem + char *Join
*/
	return (0);
}

/*
 ** return (1) --> la ligne a ete lue
 ** return (0) --> la lecture est terminee
 ** return (-1)--> erreur
 */
