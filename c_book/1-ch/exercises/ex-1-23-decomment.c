#include<stdio.h> // comment
#define MAX 1000  /* comment */
#define IN 1 
#define OUT 0

int state = OUT;

void rmcomment(char[], int);
void rmmultcom(char[], int);

/*
 * Removes all comments from C code.
 */

/* 1 this one */
/** 2 this one */
/*** 3 this one */
/*** 4 this one **/
// 5 this one 
int getnextline(char s[], int limit)
{
   int i, c;
   
   for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
     s[i] = c;
   } 

   if (c == '\n') {
     s[i] = '\n';
     ++i;   
  }

  s[i] = '\0';
   
  return i;
}

void rmmultcom(char s[], int len) {
  // printf("state %d, string: %s\n", state, s);
  // if state is OUT we look for /* 
  // if state is IN we look for */
  int i, prev_c, c, 
   pointer; // pointer where to copy chars to string
  // for (i = 0, pointer = 0; i < len; ++i) {
  // for (i = 0, pointer = 0; i < len && (s[i] != EOF && s[i] != '\n') && (s[i + 1] != EOF && s[i + 1] != '\n'); ++i) {
  for (i = 0, pointer = 0; i < len && (s[i + 1] != EOF && s[i + 1] != '\n'); ++i) {
    prev_c = s[i], c = s[i+1];
    // printf("BEGIN i = %d, pointer = %d, s[%d] = %c, prev_c = %c, c = %c, s = %s\n", i, pointer, pointer, s[pointer], prev_c, c, s);
    if (state == OUT) {
      // printf("state %d, prev_c %c at %d, c %c at %d, pointer at %d, i at %d\n", state, s[i], i, s[i+1], i+1, pointer, i);
       if (prev_c == '/' && c == '*') {
        state = IN;
        pointer = i;
        // printf("state => IN prev_c %c at %d, c %c at %d, pointer at %d, i at %d\n", s[i], i, s[i+1], i+1, pointer, i);
        // printf("state => IN prev_c %c at %d, c %c at %d, pointer at %d, i at %d => %s\n", s[i], i, s[i+1], i+1, pointer, i, s);
      } else {
        // printf("COPY s[%d] = s[%d]: %c = %c\n", pointer, i, s[pointer], s[i]);
        // printf("state %d copy s[%d] = s[%d]: %c = %c, prev_c = %c : %s\n", state, pointer, i, s[pointer], s[i], prev_c, s);
        if (!(prev_c == '/' && s[i-1] == '*')) {
          s[pointer] = prev_c;
          ++pointer;
        }
      }

    } else if (state == IN) {
      // printf("state %d, prev_c %c at %d, c %c at %d, pointer at %d, i at %d\n", state, s[i], i, s[i+1], i+1, pointer, i);

      if (prev_c == '*' && c == '/') {
      // printf("state => OUT prev_c %c at %d, c %c at %d, pointer at %d, i at %d nw? %d\n", s[i], i, s[i+1], i+1, pointer, i, s[i+2] == '\n');
        state = OUT;
      } 
    }
  }
  // printf("pointer = %d, i = %d, len %d, string = %s\n", pointer, i, len, s);
  if (state == IN && pointer == 0 && (i == len-2 || i == len)) {
   /*
    * handles this comment 
    *
    */ 
   s[0] = '\0';
  } else if (s[i+1] == EOF || s[i+1] == '\n') {
    // don't forget the last character 
    if (s[i-1] == '*' && s[i] == '/') {
      // unless it's a closing ''
      s[pointer] = s[i+1];
    } 
    else if (s[i-1] == '/' && s[i] == '*') {
    // printf("AAAA\n");
     s[pointer] = '\0';
    }
    else {
     s[pointer] = s[i];
      ++pointer;
     s[pointer] = '\n';
      // s[pointer] = '\0';
    }
  }
  // printf("\nexit: state %d, pointer %c at %d, i %c at %d\n", state, s[pointer], pointer, s[i], i);
  
  // wrap up the line 
  s[pointer + 1] = '\0';
}

void rmcomment(char s[], int len) {
  int i, prev_c, c;
  for (i = 0; i < len && !((prev_c = s[i]) == '/' && (c = s[i + 1]) == '/'); ++i);
  
  if (i > 0) {
    s[i] = '\n';
    ++i;   
  }
  s[i] = '\0';
}


int main(void)
{
  int len;
  char s[MAX];

  while ((len = getnextline(s, MAX)) > 0) {
    rmcomment(s, len);
    rmmultcom(s, len); 
    printf("%s", s);
  }

  return 0;
}


