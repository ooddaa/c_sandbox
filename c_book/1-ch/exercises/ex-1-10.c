#include <stdio.h>

#define OUT 0 
#define IN  1

/*
 * Write a program to replace each 
 * \t -> "\t"
 * ' ' -> "\b"
 * \ -> "\\"
 * to make them visible to reader
 */

int main(void)
{
  int c;

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      printf("\\t");
    } else if (c == ' ') {
      printf("\\b");
    } else if (c == '\\') {
      printf("\\");
    } else {
      putchar(c);
    }
  }
  return 0;
}
