#include<stdio.h>

#define IN  1
#define OUT 0
#define MAX_BARS 20

/*
 * Write program that prints the histogram
 * of the lenghts of the words in its input.
 * 
 * DONE:
 * - print total for each histogram in the 
 *   end of the line:  
 *   1   |              [1]
 *   2   ||||           [4]
 *
 * - print header: 
 *   Len Count          Total
 *   1   |              [1]
 *   2   ||||           [4]
 *
 * TODO: 
 * - make it print vertical bars
 *
 * EXAMPLE:
 *
 
    Len Count                   Total
    1   ||||                    [4]
    2   ||||||||||||||||||||+   [28]
    3   ||||||||||||||||||||+   [32]
    4   ||||||||||||||||||||+   [46]
    5   ||||||||||||||||||||+   [71]
    6   ||||||||||||||          [14]
    7   ||||||||||||||||||||+   [34]
    8   ||||||||||||||||||      [18]
    9   ||||||||||||||||||||+   [25]
    10  |||                     [3]
    10+ ||||||                  [6]
 
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

  printf("Len Count                   Total\n");
  for (i = 0; i <= 10; ++i) {
    if (i == 9) {
      printf("10  ");
    } else if (i == 10) {
      printf("10+ ");
    } else {
      printf("%d", i + 1);
      printf("   ");
    }

    // print bars 
    for (bars = 1; bars <= words[i] ; ++bars) {
      if (bars < MAX_BARS) printf("|");
      else if (bars == MAX_BARS) printf("|+");
    }
    
    // calculate padding to print "[total_count]"
    for (int j = 0; j <= (MAX_BARS + 1 /* the possible last '+' */) - bars; ++j) {
      printf(" ");
    }
    printf("  [%d]\n", words[i]);
  } 

  return 0;
}
