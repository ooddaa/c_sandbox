#include<stdio.h>

int binsearch(int, int[], int); 
int binsearch(int x, int v[], int len) 
{
  int low, high, mid;
  low = 0;
  high = len - 1;
  
  while (low <= high) {
    mid = (high + low) / 2;
    if (x == v[mid]) return mid;
    if (x < v[mid]) {
      high = mid;
    } else {
      low = mid + 1;
    }
  }
   return -1;
}


int main(void)
{
  int v[10] = {1,2,3,4,5,6,7,8,9,10};
  printf("%d\n", binsearch(5, v, 10)); // 4
  printf("%d\n", binsearch(57, v, 10)); // -1
  printf("%d\n", binsearch(7, v, 115)); // 6 <- hmm correct
  return 0;
}
