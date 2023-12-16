
#include "get_next_line.h"

int main(void)
{
  int    fd;
  char  *next_line;
  int  count;

  count = 0;
  fd = open("text.txt", O_RDONLY);
   if (fd == -1)
 {
   printf("Error opening file");
  return (1);
 } 
	next_line = get_next_line(fd);
	printf("part:%s\n", next_line);
	next_line = NULL;
  close(fd);
  return (0);
}