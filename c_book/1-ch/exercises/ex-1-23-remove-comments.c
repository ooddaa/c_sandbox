#include<stdio.h>
#define MAX 1000 
#define IN 1 
#define OUT 0
int comment = OUT;
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
   int i, c, prev_c = -1, cond = 1; // 6 this one 
   for (i = -1; i < limit /* 7 this one */ && cond && (c = getchar()) != EOF && c != '\n'; ++i) {
   if (i < 0) { 
   prev_c = c;
      // printf("i %d, prev_c %d, c %c\n", i, prev_c, c);
   } else {
      if (prev_c == '/' && c == '/') {
        cond = 0;
      }
     if (prev_c == '/' && c == '*') {
      comment = IN;
     }
     if (prev_c == '*' && c == '/') {
      comment = OUT;
     }
     if (!comment) {
      // printf("i %d, prev_c %d, c %c\n", i, prev_c, c);
      s[i] = prev_c; 
      prev_c = c;
     }
    } 
   } /*
8 this one 
   */
/**
 * 9 and this one 
 * */
// printf("last: i %d, s[i] %c\n", i, s[i]);
  s[i] = prev_c;
  s[i+1] = '\n';
  s[i+2] = '\0';
   
   return i;
}



int main(void)
{
  int len;
  char s[MAX];

  while ((len = getnextline(s, MAX)) != 0) {
    printf("[%d] %s", len, s);
  }

  return 0;
}


