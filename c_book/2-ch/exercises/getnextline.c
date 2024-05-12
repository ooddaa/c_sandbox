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
