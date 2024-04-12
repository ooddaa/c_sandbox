#include<stdio.h>

/*
 * Converts Celsius to Fahrenheit. 
 */

float celcius_to_fahr(float cels);

int main(void)
{
  float celcius;
  int lower, upper, step;

  lower = -50;
  upper = 100;
  step = 20;

  celcius = lower;
  while (celcius <= upper) {
    printf("%3.0f %6.1f\n", celcius_to_fahr(celcius), celcius);
    celcius += step;
  }

  return 0;
}

float celcius_to_fahr(float cels) 
{
  return cels/(5.0/9.0) + 32.0;
}
