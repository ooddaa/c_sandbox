#include<stdio.h>

int main(void) 
{
  long dick;
  double trouble;
  dick = 123123;
  printf("char is %lu byte\n", sizeof(char));
  printf("int  is %lu bytes\n", sizeof(int));
  printf("long is %lu bytes\n", sizeof(long int));
  printf("float is %lu bytes\n", sizeof(float));
  printf("double is %lu bytes\n", sizeof(double));
  printf("long double is %lu bytes\n", sizeof(long double));
  /*
    char is 1 byte
    int  is 4 bytes
    long is 8 bytes
    float is 4 bytes
    double is 8 bytes
    long double is 16 bytes
  */
}
