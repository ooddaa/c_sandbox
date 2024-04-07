#include<stdio.h>

int main(void)
{
  int c, i, nwhite = 0, nother = 0, ndigit[10];

  /* if we don't init this, we'll get random numbers */
  for (i = 0; i <= 9; ++i) ndigit[i] = 0;
  

  while ((c = getchar()) != EOF)
    if (c >= '0' && c <= '9') 
      ++ndigit[c-'0']; // ugly conversion to int
    
    else if (c == ' ' || c == '\t' || c == '\n') 
      ++nwhite;
    
    else 
      ++nother; 
    
  

  printf("Digits: ");
  for (i = 0; i <= 9; ++i) printf("%d ", ndigit[i]);
  
  printf("\nWhitespace: %d\n", nwhite);
  printf("Others: %d\n", nother);

  return 0;
}
