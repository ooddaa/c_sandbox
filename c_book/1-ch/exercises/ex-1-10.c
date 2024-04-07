#include <stdio.h>

#define OUT 0 
#define IN  1

/*
 * Write a program to replace each 
 * \t -> "\t"
 * ' ' -> "\b"
 * \\ -> "\\"
 * to make them visible to reader
 */

int main(void)
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    }
    if (c == ' ') {
      printf("\\b");
    }
    if (c == '\\') {
      printf("\\");
    }
    putchar(c);
  }
  return 0;
}
