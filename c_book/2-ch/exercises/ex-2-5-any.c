#include<stdio.h>
#define MAX 100

/*
 * int any(char[] s1, char[] s2) 
 * returns first location in s1 
 * where any char of s2 is found 
 * retunrs -1 if nothing is found
 * */

int any(char[], char[]);
int any(char s1[], char s2[]) 
{
  int i = 0, k, loc = -1;

  while (loc < 0 && s1[i] != '\0') {
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) loc = i;
    }
    ++i;
  }

  return loc;
}

int main(void)
{
 
  printf("%d\n", any("lol", "abc")); // -1
  printf("%d\n", any("lol", "al")); // 0
  printf("%d\n", any("ol", "al")); // 1
  printf("%d\n", any("abcde", "xyze")); // 4

  return 0;
}
