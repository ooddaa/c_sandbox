#include <stdio.h>

#define OUT 0 
#define IN  1

/*
 * Write a program to copy its input 
 * to its output replacing each string
 * of one or more blanks by a single blank.
 */

int main(void)
{
  int c, state = OUT;

  while ((c = getchar()) != EOF) {
    if (c == ' ' && state == OUT) 
    {
      state = IN;
      putchar(c);
    }
    else if (c != ' ') {  
      state = OUT;
      putchar(c);
    }
  }
  return 0;
}
