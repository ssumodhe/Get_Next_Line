/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssumodhe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:25:41 by ssumodhe          #+#    #+#             */
/*   Updated: 2017/02/02 21:20:32 by ssumodhe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

#define BUFF_SIZE 100

# define RESET	   "\033[0m"
# define HIGHLIGHT "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK     "\033[5m"
# define BLACK     "\033[30m"
# define RED       "\033[31m"
# define GREEN     "\033[32m"
# define YELLOW    "\033[33m"
# define BLUE      "\033[34m"
# define PURPLE    "\033[35m"
# define CYAN      "\033[36m"
# define WHITE     "\033[37m"

typedef	struct	s_GNL
{
	char	*Clem;
	char	*Join;
}				t_GNL;

int				get_next_line(const int fd, char **line);

#endif
