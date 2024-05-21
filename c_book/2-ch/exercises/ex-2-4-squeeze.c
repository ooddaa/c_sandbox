#include<stdio.h>
#define MAX 100

/*
 * squeeze(char[] s1, char[] s2) 
 * deletes every character from s1 
 * that matches any character in s2
 * */

void squeeze(char[], char[]);
void squeeze(char s1[], char s2[]) 
{
  int i, j, k, match = 0;
  
  for (i = j = 0; s1[i] != '\0'; ++i) {
    for (k = 0; s2[k] != '\0'; ++k) {
      if (s1[i] == s2[k]) match = 1;
    }
    if (!match) s1[j++] = s1[i];  
    match = 0;
  }
  s1[j] = '\0'; 
}

int main(void)
{
  char s1[10] = "lobananal";
  char s2[5] = "lol";
 
  squeeze(s1, s2);

  printf("%s\n", s1);

  return 0;
}
