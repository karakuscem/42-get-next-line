/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarakus <ckarakus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 00:59:48 by ckarakus          #+#    #+#             */
/*   Updated: 2023/01/13 16:22:34 by ckarakus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*to_return;
	int		s1_len;
	int		s2_len;
	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	s2_len = ft_strlen(s2);
	to_return = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!to_return)
		return (NULL);
	ft_memcpy(to_return, s1, s1_len);
	ft_memcpy(to_return + s1_len, s2, s2_len + 1);
	return (to_return);
}

int	ft_strlen(const char *s)
{
	if (*s)
		return (1 + ft_strlen(s + 1));
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

int	ft_strchr(const char *s, int c)
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