#include <stdio.h>
#include <ctype.h>

int main(void) {
  printf("%c is upper: %i\n", 'B', isupper('B'));
  printf("%c is alpha: %i\n", '!', isalpha('!'));
  printf("%c is digit: %i\n", '2', isdigit('2'));

  return 0;
}
