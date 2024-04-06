#include <stdio.h>
int main(void)
{
  float fahr, celsius;
  int lower, upper, step;

  for (lower=0, upper=300, step=20, fahr=lower; fahr <= upper; fahr += step)
    printf("%3.0f %6.1f\n", fahr, (5.0/9.0) * (fahr - 32.0)); 

  return 0;
}
