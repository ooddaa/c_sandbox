#include<stdio.h>
#define MAXLENGTH 1000
/*
 * Reads text input. 
 * Outputs the longest line and its length. 
 * */

int getnextline(char[], int);
void copy(char[], char[]);

/*
 * Point of this excercise is to get used 
 * to the the fact that arrays are passed
 * by reference. ie funciton receives the 
 * address of the beginning of the array. 
 *
 * There is no copying of elements. 
 * 
 * That is why we can directly change 
 * array's elements as we have direct 
 * access to their memory locations. 
 * 
 * This function: 
 * - checks if there's any more input to 
 *   process;
 * - if not, returns 0;
 * - else, grabs the line (ends with \n);
 * - records it as current (by reference);
 * - returns its length;
 * */
int getnextline(char currentline[], int maxlength) {
  int i, c;
  for (i = 0; i < maxlength-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
  // this will also work, but uglier 
  // for (i = 0, c = getchar(); i < maxlength-1 && c != EOF && c != '\n'; ++i, c = getchar()) {
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
