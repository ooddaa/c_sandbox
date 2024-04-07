#include<stdio.h>

#define IN 1
#define OUT 0

int main(void)
{
 int c, wc = 0, state = OUT, is_letter;

 while ((c = getchar()) != EOF) {
    is_letter = (c != ' ' && c != '\t' && c != '\n');
  if (state == OUT && is_letter) {  
    ++wc;
    state = IN; 
  }
  else if (state == IN && !is_letter) {
    state = OUT;
  }
 }

 printf("Word count: %d\n", wc);  
 return 0;
}
