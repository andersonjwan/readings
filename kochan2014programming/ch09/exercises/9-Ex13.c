#include <stdio.h>

void uppercase(char []);

int main(void) {
  char stringSource[] = "uppercase";
  printf("Original: %s\n", stringSource);

  uppercase(stringSource);
  printf("New: %s\n", stringSource);
  return 0;
}

void uppercase(char string[]) {
  int i;

  for(i = 0; string[i] != '\0'; ++i) {
    string[i] = string[i] - 'a' + 'A';
  }
}
