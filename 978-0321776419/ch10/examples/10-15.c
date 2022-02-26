#include <stdio.h>

int stringLength(const char *);

int main(void) {
  printf("%i   ", stringLength("stringLength test"));
  printf("%i   ", stringLength(""));
  printf("%i\n", stringLength("complete"));
  return 0;
}

int stringLength(const char *string) {
  const char *iter_ptr = string;

  while(*iter_ptr != '\0') {
    ++iter_ptr;
  }

  return iter_ptr - string;
}
