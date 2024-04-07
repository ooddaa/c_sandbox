#include <stdio.h>

// != expression only has 
// two possible values
// true || false 
// 1 || 0
// so what are we supposed 
// to verify here besides this?

int main(void)
{
  int c;

  while ((c = getchar()) != EOF) 
    printf("%d\n", c); 

  /* ex 1-7 */
  printf("EOF: %d\n,", c);
  
  return 0;
}
