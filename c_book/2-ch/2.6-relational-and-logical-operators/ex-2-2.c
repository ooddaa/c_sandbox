#include <stdio.h>

int main(void)
{
  int i, lim = 10;
  char c;
  char s[lim];
  
  // Don't forget to update c ! Otherwise we always end up with the first character. 
  // If we put (c = getchar()) into condition section, we'll get "unsequenced access".
  for (i = 0, c = getchar(); i < lim-1 && (c != '\n') && (c != EOF); ++i, c = getchar()) {
    s[i] = c;
  }
  printf("%s\n", s);
  return 0;
}
