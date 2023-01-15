/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:37:48 by ckarakus          #+#    #+#             */
/*   Updated: 2023/01/15 17:10:58 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
    # define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
int	    ft_strchr(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int	    ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char    *ft_new_stash(char *stash);
char    *ft_get_line(char *stash);
char    *ft_read(int fd, char *stash);

#endif
