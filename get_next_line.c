/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:36:37 by ckarakus          #+#    #+#             */
/*   Updated: 2023/01/15 17:11:02 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
    static char *stash;
    char        *to_return;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = ft_read(fd, stash);
    if (!stash)
        return (NULL);
    to_return = ft_get_line(stash);
    stash = ft_new_stash(stash);
    return (to_return);
}

char    *ft_read(int fd, char *stash)
{
    char    *buff;
    int     check;

    check = 1;
    buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
    if (!buff)
        return (NULL);
    while (check != 0 && !ft_strchr(stash))
    {
        check = read(fd, buff, BUFFER_SIZE);
        if (check == -1)
        {
            free(buff);
            return (NULL);
        }
        buff[check] = '\0';
        stash = ft_strjoin(stash, buff);
    }
    free(buff);
    return (stash);
}

char    *ft_get_line(char *stash)
{
    char    *to_return;
    int     i;

    if (!stash)
        return (NULL);
    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    to_return = malloc(sizeof(char) * (i + 2));
    if (!to_return)
        return (NULL);
    i = -1;
    while (stash[++i] && stash[i] != '\n')
        to_return[i] = stash[i];
    if (stash[i] == '\n')
    {
        to_return[i] = '\n';
        i++;
    }
    to_return[i] = '\0';
    return (to_return);
}

char    *ft_new_stash(char *stash)
{
	int		i;
	int		j;
	char	*to_return;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
        free(stash);
        return (NULL);
    }
	to_return = malloc(sizeof(char) * (ft_strlen(stash) - i + 1));
	if (!to_return)
		return (NULL);
	i++;
	j = 0;
	while (stash[i])
		to_return[j++] = stash[i++];
	stash[j] = '\0';
	free(stash);
	return (to_return);
}
