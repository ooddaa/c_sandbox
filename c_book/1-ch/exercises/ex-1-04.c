#include <stdio.h>
int main(void)
{
  float fahr, celcius;
  int lower, upper, step;

  lower = -40;
  upper = 50;
  step = 10;

  celcius = lower;
  while (celcius <= upper) {
    fahr = celcius / (5.0/9.0) + 32.0;
    printf("%6.1f %3.0f\n", celcius, fahr);
    celcius += step;
  }

  return 0;
}
