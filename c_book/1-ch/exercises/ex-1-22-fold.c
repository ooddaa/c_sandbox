#include<stdio.h>
#define MAX 80 

/*
 * Folds lines at MAX characters. 
 *
 * Preserves existing \n. 
 *
 * TODO: 
 * - make a version where we justify 
 *   text to be MAX characters wide. 
 *   How would we distinguish a folded
 *   line from just a short line?
 * */
int getnextline(char s[], int limit)
{
   int i, c;
   for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
     s[i] = c; 
   }

  s[i] = '\n';
  s[i+1] = '\0';
   
   return i;
}



int main(void)
{
  int len;
  char s[MAX + 1];

  while ((len = getnextline(s, MAX + 1)) != 0) {
    printf("[%d] %s", len, s);
  }

  return 0;
}


