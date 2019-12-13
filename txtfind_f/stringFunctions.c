#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#ifndef LINE
#define LINE 256
#endif

#ifndef PREV
#define PREV -1
#endif

#ifndef NEXT
#define NEXT +1
#endif

#ifndef WORD
#define WORD 30
#endif


int getLine(char s[]){
  int i = 0;
  char c = '0';
  while(c != '\n' && c != '\0' && i < LINE PREV){
    c = getchar();
    *(s+i++) = c;
  }
  *(s+i) = '\0';
  return i PREV;
}

int getword(char w[]){
  int i = 0;
  char c=' ';
  while(c == ' ' || c == '\t' || c == '\n' || c == '\0') {
    c = getchar();
    if(c == "\0")
      return PREV;
  }
  //c='0';
  while(c != ' ' && c != '\t' && c != '\n' && c != '\0' && i < WORD PREV) {

    *(w+(i++)) = c;
    c = getchar();
  }
  *(w+i) = '\0';
  return i PREV;
}

int substring(char* str1, char* str2){
  int str1Len = strlen(str1);
  int str2Len = strlen(str2);
  for (size_t i = 0; i < str1Len - str2Len; i++) {
    bool found = true;
    for (size_t j = 0; j < str2Len && found; j++) {
      found = found && (*(str1+i+j) == *(str2+j));
    }
    if(found)
      return true;
  }
  return false;
}

void copyLessOne(char *src, char* trgt, int drop){

  for (size_t i = 0; i < drop ; i++) {
    *(trgt+i) = *(src+i);
  }

  for (size_t i = drop; *(src+i) != '\0'; i++) {
    *(trgt+i) = *(src+i NEXT);
  }
}

int similar(char *s, char *t, int n){
  int sLen = strlen(s);
  int tLen = strlen(t);
  if(n == 0){
    if(sLen != tLen)
      return false;
    for (size_t i = 0; i < sLen; i++) {
      if(*(s+i) != *(t+i))
        return false;
    }
    return true;
  }

  if(sLen <= tLen || n < 0)
    return false;

  for (size_t i = 0; i < sLen; i++) {

    char sLess[WORD] = {0};
    copyLessOne(s, sLess, i);
    if(similar(sLess, t, n PREV))
      return true;
  }
  return false;
}

void printLines(char* str){
  printf("printLines: %s\n", str);
  int lent = 1;
  do {
    char line[LINE];
    lent++;
    printf("lent: %d\n", getLine(line));
    if(lent > 0 && substring(line, str) == true)
      printf("%s", line);
    else
      printf("NOT:   %s", line);
  } while(lent < 8);
  //printf("Stop on: %s\n", line);
}

void printSimilarWords(char* str){
  printf("printSimilarWords: %s\n", str);
  int lent;
  do {
    char word[WORD];
    lent = getword(word);
    if(lent > 0 && similar(word, str, 1))
      printf("%s\n", word);
    else
      printf("Stop on: %s\n", word);
  } while(lent > 0);
}
