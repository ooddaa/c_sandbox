#include<stdio.h>

#define IN  1
#define OUT 0

/*
 * Write program that prints its 
 * input one word per line.
 */

int main(void) 
{
  int c, state = OUT, is_letter; 

  while ((c = getchar()) != EOF) {
    is_letter = (c != ' ' && c != '\n' && c != '\t');
    
    if (state == OUT && is_letter) {
      putchar(c);
    } 
    else if (state == IN && is_letter) {
      putchar('\n');
      putchar(c);
      state = OUT;
    }
    else if (state == OUT && !is_letter) {
      state = IN;
    }
  }

  return 0;
}
