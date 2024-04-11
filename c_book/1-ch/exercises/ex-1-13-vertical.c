#include<stdio.h>

#define IN  1
#define OUT 0
#define MAX_BARS 10

/*
 * Write program that prints a vertical histogram
 * of the lenghts of the words in its input.
 *
 * EXAMPLE:
 *
 
     2   3   4   1   0   2   1   1   1   1   2 
             | 
         |   |
     |   |   |           |                   |
     |   |   |   |       |   |   |   |   |   |
     1   2   3   4   5   6   7   8   9   10  10+
     
 */

int main(void) 
{
  int i, c, bars, wl, state, is_letter; 
  int words[11];  // [1_letter_words, 2_letter_words...10+_letter_words]

  wl = 0;         // word length 
  state = OUT; 

  for (i = 0; i < 11; ++i) words[i] = 0;
  

  while ((c = getchar()) != EOF) {
    is_letter = (c != ' ' && c != '\n' && c != '\t');
    
    if (state == OUT && is_letter) {
      state = IN;
      ++wl; 
    } else if (state == IN && is_letter) {
      ++wl;
    } else if (state == IN && !is_letter) {
      state = OUT;
      ++words[wl-1]; // who doesn't love 0-based indices 
      wl = 0;
    }
  }

  // print totals 
  for (i = 0; i <= 10; ++i) {
    if (words[i] < 10) {
      printf("%d   ", words[i]);
    } else if (words[i] < 100) {
      printf("%d  ", words[i]);
    } else if (words[i] < 1000) {
      printf("%d ", words[i]);
    } else {
      printf(">1k ");
    }
  }
  printf("\n");

  // print histogram
  for (bars = MAX_BARS; bars > 0 ; --bars) {
    for (i = 0; i <= 10; ++i) {
      if (words[i] < bars) {
        printf("    ");
      } else {
        printf("|   ");
      }
    }
    printf("\n"); 
  }
  printf("1   2   3   4   5   6   7   8   9   10  10+");

  return 0;
}
