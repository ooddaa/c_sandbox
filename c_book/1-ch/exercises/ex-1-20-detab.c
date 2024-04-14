#include<stdio.h>
#define MAX 1000 
#define BLANK_PER_TAB 4 

/*
 * Replaces \t with a correct number of blanks.
 *
 * TODO: refactor
 * */

void detab(char[], char[], int); 

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
   
   return i;
}

void detab(char from[], char to[], int len) 
{
  // go in BLANK_PER_TAB chunks
  // if encounters \t, replace it with ' '
  // and pad with blanks till next Tab stop
  // Each Tab stop == 4 blanks 
  int i, j, pos, c;

  i = 0;
  j = 0;
  pos = BLANK_PER_TAB;
  for (; i < len && j < MAX && (c = from[i]) != EOF && c != '\n' && c != '\0'; ++i) {
      if (c == '\t') {
      for (; pos > 0; --pos) {
        to[j] = ' ';
        ++j;
      }
      pos = BLANK_PER_TAB;
    } else {
      to[j] = c;
      ++j;
      if (pos == 1) { 
        pos = BLANK_PER_TAB;
      } else {
        --pos;
      }
    }
  }

  to[j] = '\n'; 
  ++j;
  to[j] = '\0'; 
} 


int main(void)
{
  int len;
  char s[MAX], f[MAX];

  while ((len = getnextline(s, MAX)) != 0) {
    printf("Original:%s\n", s);
    
    detab(s, f, len);
    printf("Detabbed:%s\n", f);
  }

  return 0;
}


