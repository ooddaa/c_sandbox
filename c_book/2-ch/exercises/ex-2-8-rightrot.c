#include<stdio.h>

/*
 * Write function rightrot(x,n) that returns the 
 * value of integer x rotated to the right n positions. 
 *
 * x 0000 0011  // 
 * n 1          // 
 * r 1000 0001  //
 *
 * x 0000 1011  // 
 * n 4          // 
 * r 1011 0000  //
 * 
 * */

unsigned rightrot(unsigned, unsigned);
unsigned rightrot(unsigned x, unsigned n) 
{
  for (int i = 0; i < n; ++i) 
  {
    unsigned leftmost = x << (sizeof(unsigned) * 8 - 1);
    unsigned shifted_x = x >> 1;
    x = shifted_x | leftmost;
  }
  return x;
}

int main(void)
{ 
  unsigned zero = 0b00000000000000000000000000000000u; 
  unsigned val1 = 0b10000000000000000000000000000000u; 
  unsigned val2 = 0b00000000000000000000000000000001u; 
  unsigned val3 = 0b10101000000000000000000000000000u; 
  unsigned val4 = 0b00000000000000000000000000010101u; 
  unsigned val5 = 0b11111000000000000000000000000000u; 
  unsigned val6 = 0b00000000000000000000000000011111u; 
  unsigned val7 = 0b00000000000000000000000000000001u; 
  unsigned val8 = 0b00000000000000000000000000000010u; 

  printf("%u\n", zero == rightrot(zero, 123)); // 1
  printf("%u\n", val1 == rightrot(val2, 1)); // 1
  printf("%u\n", val3 == rightrot(val4, 5)); // 1
  printf("%u\n", val5 == rightrot(val6, 5)); // 1
  printf("%u\n", val7 == rightrot(val8, 1)); // 1
  return 0;
}
