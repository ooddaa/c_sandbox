#include<stdio.h>

/**
 * This version sux.
 *
 * - more complicated while test
 * - more complicated mid setup 
 * - index var might be dropped, but that 
 *   would add additional else. 
 * - first version is better.   
 * 
 * */
int binsearch(int, int[], int); 
int binsearch(int x, int v[], int len) 
{
  int low, high, mid, index;
  low = 0;
  high = len - 1;
  index = -1;
  
  mid = (high + low) / 2;
  while (low <= high && x != v[mid]) {
    if (x < v[mid]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
    mid = (high + low) / 2;
  }

  if (x == v[mid]) index = mid;
  return index;
}


int main(void)
{
  int v[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("%d\n", binsearch(5, v, 10)); // 4
  printf("%d\n", binsearch(57, v, 10)); // -1
  return 0;
}
