#include <stdio.h>

void copyString(char *, char *);

int main(void) {
  char string[] = "This is a string";
  char string_copy[81];

  copyString(string_copy, string);
  printf("%s\n", string_copy);

  copyString(string_copy, "So is this.");
  printf("%s\n", string_copy);
  return 0;
}

void copyString(char *to, char *from) {
  while(*from) {
    *to++ = *from++; // post-increment
  }

  *to = '\0';
}
