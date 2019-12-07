#include <stdio.h>
#include "stringFunctions.h"

int main(){
  char s[WORD] = "fblga";
  char t[WORD] = "bla";

  //getword(s);
  //getword(t);
  int ans = 0;//similar(s, t, 2);
  if(ans)
    printf("similar\n");
  else
    printf("not similar\n");

  printf("s - 0: %s\n", copyLessOne(s, 0));
  return 0;
}
