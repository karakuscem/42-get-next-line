#include "get_next_line.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
    unsigned char *d;
    unsigned char *s;

    if (!dst && !src)
        return (NULL);
    d = (unsigned char *)dst;
    s = (unsigned char *)src;
    while (n--)
        *d++ = *s++;
    return (dst);
}

void *ft_calloc(size_t count, size_t size)
{
    void *space;

    space = malloc(count * size);
    if (!space)
        return (0);
    ft_memset(space, 0, count * size);
    return (space);
}

size_t ft_strlen(const char *s)
{
    if (*s)
        return (1 + ft_strlen(s + 1));
    return (0);
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *new_str;
    size_t s1_len;
    size_t s2_len;

    if (!s1 || !s2)
        return (NULL);
    s1_len = ft_strlen(s1);
    s2_len = ft_strlen(s2);
    new_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
    if (!new_str)
        return (NULL);
    ft_memcpy(new_str, s1, s1_len);
    ft_memcpy(new_str + s1_len, s2, s2_len);
    return (new_str);
}