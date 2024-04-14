#include<stdio.h>
#define MAX 1000 

/*
 * Deletes trailing blanks and tabs from lines. 
 * Deletes blank lines. 
 *
 * Prints results to stdout. 
 * */

int getnextline(char[], int);
void trimline(char[], int); 

int getnextline(char s[], int limit)
{
   int i, c;
   
   for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
     s[i] = c;
   } 

   if (c == '\n') {
     s[i] = '\n';
     ++i;   
  }

   s[i] = '\0';
   
   trimline(s, i);
   return i;
}

// removes trailing ' ' and \t 
void trimline(char s[], int len) 
{
   int i = len - 1;
   while (i > 0 && (s[i] == ' ' || s[i] == '\t') || s[i] == '\n' || s[i] == '\0') { 
    --i;
   }
   if (i != 0) {
     ++i;
     s[i] = '\n';
     ++i;
     s[i] = '\0';
  } else {
    s[0] = '\0';
  }
} 


int main(void)
{
  int len;
  char s[MAX];

  while (getnextline(s, MAX) != 0) {
    printf("%s", s);
  }


  return 0;
}


