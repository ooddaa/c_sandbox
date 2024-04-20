#include<stdio.h> // comment
#define MAX 1000  /* comment */
#define IN 1 
#define OUT 0
#define STATE OUT

void rmcomment(char[], int);

/*
 * Removes all comments from C code.
 */

/* 1 this one */
/** 2 this one */
/*** 3 this one */
/*** 4 this one **/
// 5 this one 
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

void rmcomment(char s[], int len) {
  int i, prev_c, c;
  for (i = 0; i < len && ((prev_c = s[i]) != '/' && (c = s[i + 1]) != '/'); ++i);
  
  if (i > 0) {
    s[i] = '\n';
    ++i;   
  }
  s[i] = '\0';
}


int main(void)
{
  int len;
  char s[MAX];

  while ((len = getnextline(s, MAX)) > 0) {
    rmcomment(s, len);
    printf("%s", s);
  }

  return 0;
}


