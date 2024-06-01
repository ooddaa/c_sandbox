#include<stdio.h>

/*
 * Write function bitcount(unsigned x) that counts  
 * the number of 1-bits in x and returns this number
 *
 * x 0000 0011  // 2 
 * x 0000 1011  // 3
 * x 1011 0010  // 4
 * 
 * */

unsigned bitcount(unsigned);
unsigned bitcount(unsigned x)
{
   int b;
   for (int b = 1; x != 0;) if(x &= (x-1)) ++b;
  return b;
}


int main(void)
{
  printf("%u\n", bitcount(0b1)); // 1
  printf("%u\n", bitcount(0b11)); // 2
  printf("%u\n", bitcount(0b1011)); // 3
  return 0;
}
