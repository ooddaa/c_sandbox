#include<stdio.h>

int main(void)
{
 int c, lc;
 lc = 0;
 while ((c = getchar()) != EOF)
   if (c == '\n')
     ++lc;

 printf("%d\n", lc);  
 return 0;
}
