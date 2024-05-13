#include<stdio.h>
#include<math.h>
#include "./getnextline.c"
#define BASE 16
#define SIZE 9

/*
 * Converts a string of hexadecimal digits to 
 * its integer value. 
 * 
 * Example: 
 *
 * 0x1  => 1 
 * 0x11  => 17 
 * 0xA  => 10 
 * 0x1F => 31 
 * 0xEF => (15 * 16^0) + (14 * 16^1) = 15 + 225 = 240  
 * 0xCAFE => (14 * 16^0) + (15 * 16^1) + (10 * 16^2) + (12 * 16^3) = 51966
 * */

int htoi(char[], int);
int htoi(char s[], int len) 
{
  long value = 0;
  int j = 0;

  for (--len; len >= 0; --len, ++j) {
    if (s[j] >= '0' && s[j] <= '9') {
      value += (s[j] - '0') * pow(BASE, len);   
    } else if (s[j] >= 'A' && s[j] <= 'F') {
      value += (s[j] - 55) * pow(BASE, len);   
    } else if (s[j] >= 'a' && s[j] <= 'f') {
      value += (s[j] - 87) * pow(BASE, len);   
    }
  }
  return value;
}

int main(void)
{
  char s[SIZE];
  int len;
  
  while ((len = getnextline(s, SIZE)) > 0) {
    printf("%d\n", htoi(s, len));
  }
 
  return 0;
}
