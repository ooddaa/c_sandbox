#include<stdio.h>
#include<math.h>
// https://stackoverflow.com/questions/232693/including-one-c-source-file-in-another/232710#232710
// #include "../../1-ch/exercises/ex-1-17-getnextline.c"
#include "./getnextline.c"
#define BASE 16
#define SIZE 9

// unsigned int power_(int num, unsigned int exp) 
// {
//   if (exp == 0) return 1;
//
//   int i;
//   unsigned int result = num; 
//   printf("power(%d, %u)\n", num, exp);  
//   for (i = 1; i <= exp; --exp) {
//     result += num * exp; 
//   }
//   printf("result = %u\n\n", result);  
//   return result;
// }

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

int htoi2(char[], int);
int htoi2(char s[], int len) 
{
  long value;
  int j = 0;

  // TODO:
  // receive s[] without the `\n`
  // and remove --len
  for (--len; len >= 0; --len, ++j) {
    // value += s[i] * power_(BASE, i);   
    value += (s[j] - '0') * pow(BASE, len);   
    printf("s[%d] %c value: %ld, pow(BASE, %d) = %f\n", len, s[len], value, len, pow(BASE, len));
  }
  return value;
}

int htoi(void) 
{
  char c;
  char s[SIZE];
  int i, value = 0;

  // for (i = 0; i < SIZE - 1; ++i) {
  //   printf("i %d\n", i);
  //   s[i] = 0;
  // }

  // first we parse our hex string and find out its length
  // aka the highest exponent 
  // we also need to store the parsed characters 
  // for (i = 0; i < SIZE-1; ++i) {
  for (i = 0; i < SIZE-1 && ((c = getchar()) != EOF && c != '\n'); ++i) {
    // printf("i %d %c\n", i, c);
   s[i] = c;  
  };
  //
  // // As we know the highest exponent, we can calculate integer value
  printf("\n\n");

  return htoi2(s, i);

  // for (c = 0, --i; i >= 0; --i, ++c) {
  //   // value += s[i] * power_(BASE, i);   
  //   value += (s[c] - '0') * pow(BASE, i);   
  //   // printf("s[%d] %c value: %d, pow(BASE, %d) = %f\n", i, s[i], value, i, pow(BASE, i));
  // }

  // return value;
}


int main(void)
{
  char s[SIZE];
  int len;
  // printf("%d\n", htoi("1"));
  // printf("%d\n", 0xA);
  // printf("%d\n", 0x1F);
  // printf("%d\n", 0xff);
  // printf("%d\n", 0xcafe);
  while ((len = getnextline(s, SIZE)) > 0) {
    printf("%d\n", htoi2(s, len));
  }
  // printf("%d\n", 0x11);
  return 0;
}
