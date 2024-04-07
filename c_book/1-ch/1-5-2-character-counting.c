#include<stdio.h>

int main(void)
{
 /* 64 bits */
 double nc;
 nc = 0;
 for (; getchar() != EOF; ++nc)
   ;
 printf("%.0f\n", nc);  
 return 0;
}
