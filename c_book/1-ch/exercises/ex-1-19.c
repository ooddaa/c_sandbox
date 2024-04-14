#include<stdio.h>
#define MAX 1000 

/*
 * Reverses lines one line at a time. 
 *
 * Prints results to stdout. 
 * */

int getnextline(char[], int);
void reverse(char[], int); 

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
   
   reverse(s, i);
   return i;
}

// removes trailing ' ' and \t 
void reverse(char s[], int len) 
{
  int h, left, right;
  left = 0;
  right = len - 2;

  while (right > left) {
    h = s[left];
    s[left] = s[right];
    s[right] = h;
    ++left;
    --right;
  }
} 


int main(void)
{
  int len;
  char s[MAX];
  // while we have a line 
  while (getnextline(s, MAX) != 0) {
    printf("%s", s);
  }


  return 0;
}


