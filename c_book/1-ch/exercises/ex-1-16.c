#include<stdio.h>
#define MAXLENGTH 1000
/*
 * Reads text input. 
 * Outputs the longest line and its length. 
 * */

int getnextline(char[], int);
void copy(char[], char[]);

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

void copy(char to[], char from[]) {
  int i = 0;
  while ((to[i] = from[i]) != '\0') {
    ++i;
  }
}

int main(void) 
{
  int len; // length of curr line
  int max; // max length found so far 
  char currentline[MAXLENGTH]; // the currently inspected line
  char longestline[MAXLENGTH]; // the longest line found

  max = 0;
  while ((len = getnextline(currentline, MAXLENGTH)) > 0) {
    if (len > max) {
      max = len;
      copy(longestline, currentline);
    }
  }
  if (max > 0) printf("[%d] %s\n", max, longestline);
  
  return 0;
}
