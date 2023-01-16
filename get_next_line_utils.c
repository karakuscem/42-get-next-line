/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42istanbul.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:59:48 by ckarakus          #+#    #+#             */
/*   Updated: 2023/01/16 18:55:46 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strcpy(char	*dst, const char *src, int dstsize)
{
	int	i;

	i = 0;
	while (src[i] && i < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	int		len_s1;
	int		len_s2;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	to_return = malloc((len_s1 + len_s2 + 1) * sizeof(char));
	if (to_return == NULL)
		return (NULL);
	ft_strcpy(to_return, s1, len_s1);
	ft_strcpy(&to_return[len_s1], s2, len_s2);
	free(s1);
	return (to_return);
}

int	ft_strlen(const char *s)
{
	if (*s)
		return (1 + ft_strlen(s + 1));
	return (0);
}

int	ft_strchr(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return (1);
		i++;
	}
	return (0);
}
