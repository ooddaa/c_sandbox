#include<stdio.h>

/*
 * Write function setbits(x,p,n,y) that returns x with 
 * the n bits that begin at position p set to the 
 * rightmost n bits of y, leaving the other bits unchanged. 
 *
 *
 * x 0000 0001  // 1 
 * p 3          // 
 * n 2          // 0000 0011
 * y 0001 1111
 * r 0000 1101  // 13
 *
 * build p 2 n 2 ~mask   1001  
 * 1111 << n = 1100 
 * ~1100 = 0011
 * 0011 << p + 1 - n = 0110 
 * ~0110 = 1001 
 *
 * p3 n3 ~(mask) = ~1110 = 0001
 * 1111 << n = 1000
 * ~1000 = 0111
 * 0111 << p + 1 - n = 1110
 * ~1110 = 0001 
 * */

unsigned setbits(unsigned, int, int, unsigned);
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
 int offset = p + 1 - n;
 unsigned mask_x = ~(~(~0 << n) << offset);
 int mask_y = ~(~0 << n); 
 int masked_x = x & mask_x;
 int masked_y = y & mask_y;
 int shifted_y = masked_y << offset;
 int rv = masked_x | shifted_y;

 return rv; 
}

int main(void)
{
  printf("%d\n", setbits(0b1, 2, 2, 0b0110)); // 0101 => 5
  printf("%d\n", setbits(0b1111, 3, 1, 0)); // 0111 => 7
  printf("%d\n", setbits(0b1, 3, 2, 0b11111)); // 1101 => 13
  printf("%d\n", setbits(0b11111111, 7, 4, 0b11110000)); // 0000 1111 => 15
  return 0;
}
