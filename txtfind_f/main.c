#include <stdio.h>
#include "stringFunctions.h"

int main(){
  char w[WORD];
  getword(w);
  char c;
  scanf(" %c", &c);

  if(c == 'a')
    printLines(w);
  else if (c == 'b')
    printSimilarWords(w);
  else
    printf("No commend found: %c\n", c);

  return 0;
}
