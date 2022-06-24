#include <stdio.h>

void insertString(char [], const char [], int);

int main(void) {
  char sourceString[30] = "the wrong son.";
  const char addString[] = "per";

  printf("Original: %s\n", sourceString);

  insertString(sourceString, addString, 10);
  printf("New: %s\n", sourceString);
  return 0;
}

void insertString(char source[], const char insert[], int start) {
  int i, j, k;
  char tempString[81];

  // write up to the start of the insertion point
  for(i = 0, j = 0; i < start; ++i, ++j) {
    tempString[i] = source[j];
  }

  // insert string
  for(k = 0; insert[k] != '\0'; ++k, ++i) {
    tempString[i] = insert[k];
  }

  // append the rest of the source string
  while(source[j] != '\0') {
    tempString[i] = source[j];
    ++i, ++j;
  }

  // append null character
  tempString[i] = '\0';

  // rewrite over source
  for(int i = 0; tempString[i] != '\0'; ++i) {
    source[i] = tempString[i];
  }
}
