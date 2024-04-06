#include <stdio.h>

int main(void)
{
  int i, lim = 10;
  char c;
  char s[lim];
  for (i=0, c=getchar(); (i<lim-1) + (c != '\n') + (c != EOF) == 0; ++i) {
    s[i] = c;
  }
  return 0;
}
