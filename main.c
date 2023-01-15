#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int   main()
{
  int   fd1;
  int   fd2;
  int   fd3;

  fd1 = open("asd.txt", O_RDONLY | O_CREAT, 0777);
  fd2 = open("qwerty.txt", O_RDONLY | O_CREAT, 0777);
  fd3 = open("xyz.txt", O_RDONLY | O_CREAT, 0777);
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd2));
  printf("%s", get_next_line(fd3));
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd2));
  printf("%s", get_next_line(fd3));
  printf("%s", get_next_line(fd1));
  printf("%s", get_next_line(fd2));
  printf("%s", get_next_line(fd3));

  return (0);
}
