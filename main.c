#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int   main()
{
  char  *line;
  int   fd1;
  int   fd2;

  fd1 = open("asd.txt", O_RDONLY);
  fd2 = open("adf.txt", O_RDONLY);
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd1));
  return (0);
}