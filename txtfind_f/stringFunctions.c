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
  char c;
  do {
    c = getchar();
    *(s+i) = c;
    // TODO put '\n' if reach 256 (is it allowd? what to return?)
  } while(c != '\n' && i < LINE);
  return i PREV;
}

int getword(char w[]){
  int i = 0;
  char c;
  do {
    c = getchar();
    *(w+i) = c;
    // TODO put ' ' if reach 30 (is it allowd? what to return?)
  } while(c != ' ' && c != '\t' && c != '\n' && i < WORD);
  return i PREV;
}

int stringLength(char *s){
  for (size_t i = 0; i < WORD; i++) {
    if(*(s+i) == ' ' || *(s+i) == '\t' || *(s+i) == '\n' || *(s+i) == '\0')
      return i;
  }
  return WORD;
}

int substring( char * str1, char * str2){
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

char* copyLessOne(char *s, int drop){
  char t[WORD];
  strcpy(t, s);
  int lengt = strlen(s);
  for (size_t i = drop, j = 0; i <= lengt && i < WORD; i++) {
    /*if(i != drop){
      *(t+j) = *(s+i);
      j++;
    } */
    *(t+i) = *(t+i NEXT);
  }
  char *c = t;
  //printf("copy: %s, size: %ld\n", t, strlen(c));
  return c;
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
  printf("line 86\n");
  printf("sLen: %d, tLen: %d\n", sLen, tLen);
  if(sLen <= tLen)// || n < 0)
    return false;
  printf("line 91\n");

  for (size_t i = 0; i < sLen; i++) {
    char *sc = copyLessOne(s, i);
    if(similar(sc , t, n PREV))
      return true;
  }
  printf("line 98\n");

  return false;
}
