#include<stdio.h>
#define MAX 1000 

/*
 * Deletes trailing blanks and tabs from lines. 
 * Deletes blank lines. 
 *
 * Prints results to stdout. 
 * */

// get new line 
// get a line, save it 
// walk it backwards, deleting ' ' and '\t'
// until c == isletter 
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
   // printf("len: %d\n", i); 
   // while (i > 0 && (s[i] != ' ' || s[i] != '\t') && s[i] != 's') { 
   while (i > 0 && (s[i] == ' ' || s[i] == '\t') || s[i] == '\n' || s[i] == '\0') { 
    --i;
    // printf("s[%d]: %c", i, s[i]);
   // printf("--len: %d\n", i); 
   }
  // printf("s[%d] before: %c", i, s[i]);
   if (i != 0) {
     ++i;
     s[i] = '\n';
     ++i;
    // printf("s[%d] after: %c", i, s[i]);
     s[i] = '\0';
  } else {
    s[0] = '\0';
  }
} 


int main(void)
{
  int len, count = 1;
  char s[MAX];
  // while we have a line 
  while (getnextline(s, MAX) != 0) {
    printf("%s", s);
    --count;
  }


  return 0;
}


