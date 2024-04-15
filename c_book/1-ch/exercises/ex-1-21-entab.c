#include<stdio.h>
#define MAX 1000 
#define BLANK_PER_TAB 4 

/*
 * Replaces strings of blanks with
 * the minumum number of tabs and 
 * blanks to achieve the same spacing.
 *
 * */

void entab(char[], char[], int); 

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

void entab(char from[], char to[], int len) 
{
  int i, j, pos, c, count;

  i = 0;
  j = 0;
  count = 0; // counts consecutive blanks
  for (; i < len && j < MAX && (c = from[i]) != EOF && c != '\n' && c != '\0'; ++i) {
    
    for (pos = 0; pos < BLANK_PER_TAB; ++pos) { // see if there are 4 
      if(from[i + pos] == ' ') ++count;         // consecutive blanks 
    }

    if (count == 4) {   // if there are
      to[j] = '\t';     // replace those with tab
      i += 3;           // and move original input pointer to skip the blanks 
    } else {
      to[j] = c;
    }
    ++j;
    count = 0;
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
    
    entab(s, f, len);
    printf("Entabbed:%s\n", f);
  }

  return 0;
}


