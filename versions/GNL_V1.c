/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:10:36 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/01/19 12:06:09 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_buff_analysis(char *buff, char **line)
{
	int		i;
	int		a;
	char	*whatsleft;

	whatsleft = NULL;
	printf(HIGHLIGHT RED "--> Buff Analysis <--\n" RESET); //
	i = 0;
	while(buff[i] != '\0' && buff[i] != '\n') //ou bien par EOF
		i++;
	printf("BA |    i : %d\n", i); //
	if (buff[i] == '\n') // ou EOF
	{
		if ((*line = ((char *)malloc(sizeof(char) * i))) == NULL)
			exit(EXIT_FAILURE); //return ? /!\ fonction int
		i = 0;
		while (buff[i] != '\n') // ou EOF
		{
			(*line)[i] = buff[i];
			i++;
		}
		(*line)[i] = '\0';
		a = 0;
		while (buff[i] != '\0')
		{
			if ((whatsleft = (char *)malloc(sizeof(char) * 1)) == NULL)
				return (0);
			whatsleft[a] = buff[i];
			a++;
			i++;
		}
	}
	printf("BA | Line :\n\"%s\"\n", *line); //
	return (whatsleft);
}

int		get_next_line(const int fd, char **line)
{
	int		octet;
	char	buff[BUFF_SIZE];
	static char *Clem = NULL;

	printf(HIGHLIGHT RED "--> Get Next Line <--\n" RESET); //
	*line = NULL;
	if (Clem != NULL)	// --> if static != null lire dans static et end programme
	{
		ft_buff_analysis(Clem, line);
		return (0);		
	}
	octet = read(fd, buff, BUFF_SIZE);
	buff[octet + 1] = '\0';
	printf("BUFF_SIZE = %d\t | Octet in file = %d\n", BUFF_SIZE, octet); //
	printf("-----\n"); //
	printf(HIGHLIGHT"Buff :\n" RESET GREEN"%s\n" RESET, buff); //
	printf("-----\n"); //
	// --> initialiser static
	//	used = ft_buff_analysis(buff, line);
	//	printf("used = %d\n", used);
	//	used = used + ft_buff_analysis(buff, line);
	//	printf("used = %d\n", used);
	Clem = (ft_buff_analysis(buff, line));
	return (1);
}

/*
 **
 */
