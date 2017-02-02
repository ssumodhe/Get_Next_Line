/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/20 12:12:07 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_check_blanks(char *buff, int size)
{
	int		i;
	int		ok;

	i = 0;
	ok = 0;
	while (buff[i] && i < size)
	{
		ok = ok + ft_isspace(buff[i]);
		i++;
	}
	printf("size = %d | ok = %d\n", size, ok);
	if (ok == size)
		return (1);
	return (0);
}

char	*ft_buff_analysis(char *buff, char **line)
{
	int		i;
	char 	c;
	//	int		a;
	char	*whatsleft;

	printf(HIGHLIGHT RED "--> Buff Analysis <--\n" RESET); //
	whatsleft = NULL;
	if (buff == NULL)
		return (NULL);
	i = 0;
	while(buff[i] != '\0' && buff[i] != '\n')
		i++;
	if (i == 0 && !buff[i + 1])
		return (NULL);
	if (buff[i] == '\n' && !buff[i + 1])
	{
		(*line)[0] = '\n';
		return (NULL);
	}
	if(ft_check_blanks(buff, i) == 1 && !buff[i + 1]) //ATTENTION test_1
		return (NULL); 
	printf("BA |    i : %d\n", i);
	c = buff[i];
	if ((*line = ((char *)malloc(sizeof(char) * i))) == NULL)
		exit(EXIT_FAILURE); //return ? /!\ fonction int
	i = 0;
	while (buff[i] != c)
	{
		(*line)[i] = buff[i];
		i++;
	}
	(*line)[i++] = '\0';
	if (buff && buff + i)
		whatsleft = ft_strdup(buff + i); 
	printf("BA | Line :\n\"%s\"\n", *line);
	printf(CYAN"BA | Rest :\n\"%s\"\n"RESET, whatsleft);
	return (whatsleft);
}

int		get_next_line(const int fd, char **line)
{
	int		octet;
	char	buff[BUFF_SIZE];	
	static int starter = 0;
	static char *Clem = NULL;

	*line = NULL;
	if (starter == 0)
	{
		printf(HIGHLIGHT RED "--> Get Next Line <--\n" RESET); //
		octet = read(fd, buff, BUFF_SIZE);
		buff[octet + 1] = '\0';
		printf("BUFF_SIZE = %d\t | Octet in file = %d\n", BUFF_SIZE, octet); //
		printf("-----\n"); //
		printf(HIGHLIGHT"Buff :\n" RESET GREEN"%s\n" RESET, buff); //
		printf("-----\n");
		Clem = ft_buff_analysis(buff, line);
		starter++;
		if (Clem == NULL)
			return (0);
		return (1);
	}
	if (starter == 1)
	{
		Clem = ft_buff_analysis(Clem, line);
		if (Clem == NULL)
			return (0);
		return (1);
	}
	return (-1);
}

/*
 ** return (1) --> la ligne a ete lue
 ** return (0) --> la lecture est terminee
 ** return (-1)--> erreur
 */
