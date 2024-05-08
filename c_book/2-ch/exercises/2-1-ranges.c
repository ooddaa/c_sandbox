#include<stdio.h>
#include<limits.h>
#include<float.h>

int print_all_values(void)
{
  printf("Bits in a char: %d\n", CHAR_BIT);
  printf("Min val of char: %d\n", CHAR_MIN);
  printf("Signed min val of char: %d\n", SCHAR_MIN);
  printf("Max val of char: %d\n", CHAR_MAX);
  printf("Signed max val of char: %d\n", SCHAR_MAX);
  printf("Unsigned max val of char: %d\n\n", UCHAR_MAX);
  printf("Min val of int: %d\n", INT_MIN);
  printf("Max val of int: %d\n", INT_MAX);
  printf("Unsigned max val of int: %u\n\n", UINT_MAX);
  printf("Min val of long: %ld\n", LONG_MIN);
  printf("Max val of long: %ld\n", LONG_MAX);
  printf("Unsigned max val of long: %lu\n\n", ULONG_MAX);
  printf("Min val of short: %d\n", SHRT_MIN);
  printf("Max val of short: %d\n", SHRT_MAX);
  printf("Unsigned max val of short: %d\n\n", USHRT_MAX);
  printf("Min val of float: %f\n", FLT_MIN);
  printf("Max val of float: %f\n\n", FLT_MAX);
  printf("Min val of double float: %f\n", DBL_MIN);
  printf("Max val of double float: %f\n\n", DBL_MAX);
  printf("Min val of long double float: %Lf\n", LDBL_MIN);
  printf("Max val of long double float: %Lf\n\n", LDBL_MAX);
  return 0;
}

int calculate_char_max_size() 
{
  int counter = -1;
  char c = 0; 
  for (; c > -1; ++counter, ++c);
  return counter;
}

int calculate_char_min_size() 
{
  int counter = 1;
  char c = 0; 
  for (; c <= 0; --counter, --c);
  return counter;
}

int calculate_uchar_max_size() 
{
  int counter = 0;
  unsigned char c = 1; 
  for (; c != 0; ++counter, ++c);
  
  return counter;
}

int calculate_int_max_size() 
{
  long counter = -1;
  int i = 0; 
  for (; i > -1; ++counter, ++i);
  return counter;
}

int calculate_int_min_size() 
{
  long counter = 1;
  int i = 0; 
  for (; i <= 0; --counter, --i);
  return counter;
}

int calculate_and_print_all_values(void) 
{
  printf("Min val of char: %d\n", calculate_char_min_size());
  printf("Max val of char: %d\n", calculate_char_max_size());
  printf("Max val of unsigned char: %d\n\n", calculate_uchar_max_size());

  printf("Min val of int: %d\n", calculate_int_min_size());
  printf("Max val of int: %d\n\n", calculate_int_max_size());
  return 0;
}

int main(void)
{
  calculate_and_print_all_values();
  print_all_values();
  return 0;
}
