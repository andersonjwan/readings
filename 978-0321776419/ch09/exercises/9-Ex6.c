#include <stdio.h>

void removeString(char [], int, int);

int main(void) {
  char stringSource[] = "the wrong son is not very good.";
  printf("Original: %s\n", stringSource);

  removeString(stringSource, 17, 4);
  printf("New: %s\n", stringSource);

  return 0;
}

void removeString(char string[], int start, int extension) {
  int i, ii;

  // remove character(s)
  for(i = start; i < (start + extension) && string[i] != '\0'; ++i) {
    string[i] = '\?';
  }

  // shift character(s)
  for(i = start, ii = 0; string[i] != '\0'; ++i) {
    if(string[i] != '\?') {
      // shift character to new position
      string[start + ii] = string[i];

      // delete character in old position
      string[i] = ' ';
      ++ii;
    }
  }
}
