#include<stdio.h>
#define MAXLENGTH 1000
/*
 * Prints lines longer than 80 characters.
 * */

int getnextline(char[], int);

int getnextline(char currentline[], int maxlength) {
  int i, c;
  for (i = 0; i < maxlength-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
    currentline[i] = c;
  }
  if (c == '\n') { 
    currentline[i] = c;
    ++i;
  }
  currentline[i] = '\0';
  return i;
}

int main(void) 
{
  int len; // length of curr line
  int max; // max length found so far 
  char currentline[MAXLENGTH]; // the currently inspected line

  max = 0;
  while ((len = getnextline(currentline, MAXLENGTH)) > 0) {
    if (len > 80) printf("%s", currentline);
  }
  
  return 0;
}
