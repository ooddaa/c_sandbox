#include<stdio.h>

/*
 * Write function invertbits(x,p,n) that returns x with 
 * the n bits that begin at position p inverted, 
 * leaving the other bits unchanged. 
 *
 * x 0000 0001  // 1 
 * p 3          // 
 * n 2          // 
 * r 0000 1101  // 13
 * 
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

/*
 * Returns the x where any other bit, 
 * except n bits starting from p, are 
 * masked off (set to 0)
 *
 * cutbits(0b11111111, 3, 2) => 0b0000 1100
 * */
unsigned cutbits(unsigned, unsigned, unsigned);
unsigned cutbits(unsigned x, unsigned p, unsigned n) 
{
 unsigned offset = p + 1 - n;
 unsigned mask_x = ~(~0 << n) << offset;
 return x & mask_x;
}


unsigned invertbits(unsigned, unsigned, unsigned);
unsigned invertbits(unsigned x, unsigned p, unsigned n)
{
  int offset = p + 1 - n;
  unsigned y = (~cutbits(x, p, n)) >> offset;
  unsigned rv = setbits(x, p, n, y);
  return rv;
}

int main(void)
{
  printf("%d\n", invertbits(0b0001, 3, 2)); // 1 => 0b1101 = 13
  printf("%d\n", invertbits(0b1111, 3, 2)); // 15 => 0b0011 = 3
  return 0;
}
