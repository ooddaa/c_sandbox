#include <stdio.h>

int main(void)
{
  int i, lim = 100;
  char c;
  char s[lim];
  
  // Don't forget to update c ! Otherwise we always end up with the first character. 
  // If we put (c = getchar()) into condition section, we'll get "unsequenced access".
  // for (i = 0, c = getchar(); i < lim-1 && (c != '\n') && (c != EOF); ++i, c = getchar()) {
  //   s[i] = c;
  // }

  // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
  for (i = 0; i < lim - 1; ++i) {
    c = getchar();
    if (c == 'n') {
      i = lim; 
    } else if (c == EOF) {
      i = lim;
    } else {
     s[i] = c;
    }
  }

  printf("%s\n", s);
  return 0;
}
