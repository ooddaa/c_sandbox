#include <stdio.h>

/*
 * Write a program that 
 * counts blanks, tabs and
 * newlines
 */

int main(void)
{
  /* 16 bits */
  int c;
  /* 32 bits */
  long b = 0, t = 0, n = 0;

  while ((c = getchar()) != EOF) 
    if (c == ' ')
      ++b;
    else if (c == '\t')
      ++t;
    else if (c == '\n')
      ++n;

  printf("Blanks Tabs Newlines\n"); 
  printf("%6ld %4ld %8ld\n", b, t, n); 

  return 0;
}
