#include <stdio.h>

/* forward declaration(s) */
void substring(const char [], const int, int, char []);

int main(void) {
  const char sourceString[] = "character";
  char resultString[20];

  substring(sourceString, 4, 3, resultString);

  printf("Source: %s\n", sourceString);
  printf("Result: %s\n", resultString);
  return 0;
}

void substring(const char source[], const int start, int count,
               char result[]) {
  int i, j;

  for(j = 0, i = start; i < (start + count) && source[i] != '\0'; ++i, ++j) {
    result[j] = source[i];
  }

  // append null character;
  result[j] = '\0';
}
