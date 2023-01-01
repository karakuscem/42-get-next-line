#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *stash;
    char *line;
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    stash = ft_read(fd, stash);
    if (!stash)
        return (NULL);
    line = ft_get_line(stash);
    stash = ft_new_stash(stash);
    return (line);
}

char *ft_get_line(char *stash)
{
    int i;
    char *arr;

    i = 0;
    if (!stash[i])
        return (NULL);
    while (stash[i] && stash[i] != '\n')
        i++;
    arr = ft_calloc((i + 2), sizeof(char));
    if (!arr)
        return (NULL);
    i = -1;
    while (stash[++i] && stash[i] != '\n')
        arr[i] = stash[i];
    if (stash[i] == '\n')
        arr[i++] = '\n';
    return (arr);
}

char *ft_read(int fd, char *stash)
{
    char *buff;
    int check;

    if (!stash)
        return (NULL);
    buff = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    check = 1;
    while (check != 0)
    {
        check = read(fd, buff, BUFFER_SIZE);
        if (check == -1)
        {
            free(buff);
            return (NULL);
        }
        stash = ft_strjoin(stash, buff);
    }
    free(buff);
    return (stash);
}

char *ft_new_stash(char *stash)
{
    int i;
    int j;
    char *new_stash;

    i = 0;
    while (stash[i] && stash[i] != '\n')
        i++;
    if (!stash[i])
    {
        free(stash);
        return (NULL);
    };
    new_stash = ft_calloc((ft_strlen(stash) - i + 1), sizeof(char));
    if (!new_stash)
        return (NULL);
    i++;
    j = 0;
    while (stash[i])
        new_stash[j++] = stash[i++];
    free(stash);
    return (new_stash);
}