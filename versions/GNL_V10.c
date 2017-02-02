/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/02 11:48:14 by ssumodhe         ###   ########.fr       */
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
 **
 **
 */
int		ft_deal_with_it(int	chr, char *buff, char **line, char *Clem)
{
	int		i;
	char	*tmp;
	char	*buff_start;

	i = 0;
	tmp = NULL;
	buff_start = NULL;

	if (!buff)
		return (-1);

	if (chr == 0 && Clem != NULL)
	{
		tmp = ft_strdup(Clem);
		Clem = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	else if (chr == 0 && Clem == NULL)
	{
		Clem = ft_strdup(buff);
		ft_strdel(&buff);
	}
	else if (chr == 1 && buff)
	{
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		if	(((buff_start) = (char *)malloc(sizeof(char) * i)) == NULL)
			return (-1);

		if (Clem != NULL)
		{
			tmp = ft_strdup(Clem);
			(*line) = ft_strjoin(tmp, buff_start);
			ft_strdel(&tmp);
		}
		else if (Clem == NULL)
		{
			(*line) = ft_strdup(buff_start);
			ft_strdel(&buff);
		}

		if (buff[i + 1] && buff[i] != '\0')
			Clem = ft_strdup(buff + i);
		return (1);
	}
	return (0);
}

int		ft_analysis(char *buff)
{
	int		i;
	char	c;

	if (!buff)
		return (-1);
	i = 0;
	while (buff[i] != '\n' && buff[i] != '\0')
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
	int			octet;
	char		buff[BUFF_SIZE + 1];
	static char	*Clem = NULL;

	if (fd < 0 || line == NULL)
		return (-1);

	octet = 0;
	*line = NULL;

	while ((octet = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[octet] = '\0';

		if (ft_analysis(buff) == 0)
		{
			ft_deal_with_it(0, buff, line, Clem);
		}
		else if (ft_analysis(buff) == 1)
		{
			return (ft_deal_with_it(1, buff, line, Clem));
		}
		else
			return (-1);
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



