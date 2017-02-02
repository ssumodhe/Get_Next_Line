/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/02 16:59:11 by ssumodhe         ###   ########.fr       */
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
	int			octet;
	char		*tmp;
	char		*buff_stock;
	char		*buff_start;
	char		buff[BUFF_SIZE + 1];
	static char	*Clem = NULL;

	tmp = NULL;
	*line = NULL;
	buff_stock = NULL;
	buff_start = NULL;


	if (Clem != NULL)
	{
		if (buff_stock)
		{
			tmp = ft_strdup(buff_stock);
		}
		if (tmp)
		{
			buff_stock = ft_strjoin(Clem, tmp);
		}
		else if (!tmp)
		{
			buff_stock = ft_strdup(Clem);
		}
		ft_strdel(&Clem);


		if (buff_stock != NULL)
		{

			if (ft_analysis(buff_stock) == 1)
			{

				i = 0;
				while (buff_stock[i] != '\n' && buff_stock[i] != '\0')
					i++;
				if ((buff_start = (char *)malloc(sizeof(char) * i)) == NULL)
					return (-1);
				i = 0;
				while (buff_stock[i] != '\n')
				{
					buff_start[i] = buff_stock[i];
					i++;
				}
				buff_start[i] = '\0';

				(*line) = ft_strdup(buff_start);
				ft_strdel(&buff_start);

				if (buff_stock[i + 1])
					Clem = ft_strdup(&buff_stock[i + 1]);
				ft_strdel(&buff_stock);

				return (1);
			}

		}

	}





	if (buff_stock && buff_stock[0] == '\n')
	{
		if (((*line) = (char *)malloc(sizeof(char) * 1)) == NULL)
			return (-1);
		(*line)[0] = '\0';
		if (buff_stock[1])
			Clem = strdup(&buff_stock[1]);
		ft_strdel(&buff_stock);
		return (1);
	}








	while ((octet = (read(fd, buff, BUFF_SIZE))) != 0)
	{
		if (octet < 0)
			return (-1);

		buff[octet] = '\0';

		if (ft_analysis(buff) == 0)
		{
			if (buff_stock)
			{
				tmp = ft_strdup(buff_stock);
			}
			if (tmp)
			{
				buff_stock = ft_strjoin(tmp, buff);
			}
			else if (!tmp)
			{
				buff_stock = ft_strdup(buff);
			}
		}

		if (ft_analysis(buff) == 1)
		{
			i = 0;
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



			if (buff_stock)
			{
				tmp = ft_strdup(buff_stock);
			}
			if (tmp)
			{
				(*line) = ft_strjoin(tmp, buff_start);
			}
			else if (!tmp)
			{
				(*line) = ft_strdup(buff_start);
			}
			ft_strdel(&buff_stock);
			ft_strdel(&tmp);

			if (buff[i + 1] && buff[i + 1] != '\0')
				Clem = ft_strdup(&buff[i + 1]);


			return (1);

		}
	}



	if (buff_stock != NULL)
	{

		if (ft_analysis(buff_stock) == 0)
		{
			tmp = ft_strdup(buff_stock);
			(*line) = ft_strdup(tmp);
			ft_strdel(&tmp);
			ft_strdel(&buff_stock);
			return (1);
		}

		if (ft_analysis(buff_stock) == 1)
		{

			i = 0;
			while (buff_stock[i] != '\n' && buff_stock[i] != '\0')
				i++;
			if ((buff_start = (char *)malloc(sizeof(char) * i)) == NULL)
				return (-1);
			i = 0;
			while (buff_stock[i] != '\n')
			{
				buff_start[i] = buff_stock[i];
				i++;
			}
			buff_start[i] = '\0';

			(*line) = ft_strdup(buff_start);
			ft_strdel(&buff_start);

			if (buff_stock[i + 1])
				Clem = ft_strdup(&buff_stock[i + 1]);
			ft_strdel(&buff_stock);

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



