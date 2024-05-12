#include<stdio.h>
#define MAX 10000
int STATE = 0;

int rounds[MAX], round_i[1];   // arrays to hold symbols and pointer
int squigs[MAX], squig_i[1];   // pointer shows the next cell  
int squares[MAX], square_i[1];

/*
 * Checks a C programme for non matching 
 * parenthesis: 
 * () round 
 * {} squiggly 
 * [] square
 *
 * Returns a number of unmatched pairs.
 *
 * ({})[] => 0
 * ({})[  => 1
 * ({}[   => 2
 * ({[    => 3
 */

int count_brakets(int[], int, int, int, int[1]);
int count_brakets(int symbols[], int left, int right, int c, int pointer[])
{
     if (c == left) { 
       // denote opening bracket as -1
       symbols[pointer[0]] = -1;

       // later will increment round_i + 2 and store line/col 
       // printf("++pointer[0] = %d\n", pointer[0]);
       ++pointer[0];
     }

     if (c == right) {
       if (pointer[0] > 0 && symbols[pointer[0] - 1] == -1) {
         // we found a pair, close by moving pointer back 1 step 
         
         // erase the current pair  
         symbols[pointer[0]] = 0; 
         --pointer[0];
         symbols[pointer[0]] = 0;
      } else {
          // denote closing bracket as 1 
          symbols[pointer[0]] = 1;
          ++pointer[0];
       }
     }
  return 0;   
}

int count_unmatched_pairs(int);
int count_unmatched_pairs(int limit)
{
   char c;
   int i, unmatched_pairs;

   for (i = 0; i < limit && (c = getchar()) != EOF; ++i) {
    count_brakets(rounds, '(', ')', c, round_i);
    count_brakets(squigs, '{', '}', c, squig_i);
    count_brakets(squares, '[', ']', c, square_i);
   }

   unmatched_pairs = 0;
   for (i = 0; i <= round_i[0]; ++i) unmatched_pairs += rounds[i];
   for (i = 0; i <= squig_i[0]; ++i) unmatched_pairs += squigs[i];
   for (i = 0; i <= square_i[0]; ++i) unmatched_pairs += squares[i];
  
  return unmatched_pairs;
}




int main(void) 
{
  // init pointers 
  round_i[0] = 1;
  squig_i[0] = 1;
  square_i[0] = 1;
  printf("%d\n", count_unmatched_pairs(MAX));
  return 0;
}
