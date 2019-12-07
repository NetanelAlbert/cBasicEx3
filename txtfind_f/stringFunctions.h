#ifndef LINE
#define LINE 256
#endif

#ifndef PREV
#define PREV -1
#endif

#ifndef WORD
#define WORD 30
#endif

int getLine(char s[]);

int getword(char w[]);

int substring(char * str1, char * str2);

int similar (char *s, char *t, int n);

char* copyLessOne(char *s, int drop);
