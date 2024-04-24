#include<stdio.h> 
#define MAX 1000  
#define IN 1 
#define OUT 0

int state = OUT;

void rmcomment(char[], int);
void rmmultcom(char[],  int);


int getnextline(char s[], int limit)
{
   int i, c;
   for (i = 0; i < limit - 1  && (c = getchar()) != EOF && c != '\n'; ++i) {
     s[i] = c;
   } 

   if (c == '\n') {
     s[i] = '\n';
     ++i;   
  }

  s[i] = '\0';
  return i;
}

int isemptyline(char[]);
int isemptyline(char s[]) {
  if (s[0] == '\n' && s[1] == '\0') return 1;
  return 0;
};

void rmmultcom(char s[], int len) {
  if (isemptyline(s)) return;
  int i, curr_c, next_c, 
   pointer, valid_c = 0; 
  for (i = 0, pointer = 0; i < len && (s[i] != EOF && s[i] != '\n'); ++i) {
    curr_c = s[i], next_c = s[i+1];
    if (state == OUT) {
       if (curr_c == '/' && next_c == '*') {
        state = IN;
        pointer = i;
      } else {
          s[pointer] = curr_c;
          ++pointer;
          ++valid_c;
      }

    } else if (state == IN) {

      if (curr_c == '*' && next_c == '/') {
        state = OUT;
        ++i;
      } 
    }
  }

  if (state == IN && s[i] == '\n') {
    s[pointer] = '\0';
  }

  if (state == OUT && s[i] == '\n') {
    s[pointer] = '\n';
  }

  if (valid_c) {
    s[pointer + 1] = '\0';
   } else {
    s[0] = '\0';
   }
}


void rmcomment(char s[], int len) {
  if (isemptyline(s)) return;
  int i, c, valid_c = 0;
  for (i = 0; i < len - 1 && !((c = s[i]) == '/' && s[i + 1] == '/'); ++i) {
    if (c != ' ') ++valid_c;
  }
  if (valid_c) {
    s[i] = '\n';
    s[i+1] = '\0';
  } else {
    s[0] = '\0';
  }  
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
