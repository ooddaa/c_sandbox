#include<stdio.h>

/*
 * Write function lower() which converts upper case  
 * letters to lower case, with a conditional expression
 * instead of if-else
 * */

int lower(int);
int lower(int c)
{
  return c >= 'A' && c <= 'Z' ? c + 32 : c;
}


int main(void)
{
  printf("%c\n", lower('A')); // a
  printf("%c\n", lower('Z')); // z
  printf("%c\n", lower('a')); // a
  printf("%c\n", lower('b')); // b
  printf("%c\n", lower('c')); // c
  return 0;
}
