#include<stdio.h>

/*
 * Converts Celsius to Fahrenheit. 
 */

float celcius_to_fahr(float); // function prototypes 
                              // do not need variable 
                              // names in parameter
                              // declarations 

int main(void)
{
  float celcius;
  int lower, upper, step;

  lower = -50;
  upper = 100;
  step = 20;

  celcius = lower;
  while (celcius <= upper) {
    printf("%3.0f %6.1f\n", celcius_to_fahr(celcius /*actual argument (aka argument) */ ), celcius);
    celcius += step;
  }

  return 0;
}

float celcius_to_fahr(float celsius /* formal argument (aka parameter)*/) 
{
  return celsius/(5.0/9.0) + 32.0;
}
