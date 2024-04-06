#include <stdio.h>

#define PI 3.14159

int main(void)
{
  double radius = 0.0, area = 0.0;
  printf("Enter radius in meters: "); 
  scanf("%lf", &radius);
  area = PI * radius * radius;
  printf("Circle radius is %lf meters, area is: %lf\n", radius, area);
  return 0;
}
