#include <stdio.h>
#include <stdbool.h>

void readLine(char *);

int main(void) {
  char text[81];

  readLine(&text[0]);

  printf("Result: %s\n", text);

  return 0;
}

void readLine(char * textLine) {
  int i = 0;

  do {
    *(textLine + i) = getchar();
    ++i;
  }
  while(*(textLine + (i - 1)) != '\n');

  // append null character
  *(textLine + (i - 1)) = '\0';
}
