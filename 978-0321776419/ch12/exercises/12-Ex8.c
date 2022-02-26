#include <stdio.h>

#define IS_LOWER_CASE(x) (((x) >= 'a') && ((x) <= 'z'))
#define IS_UPPER_CASE(x) (((x) >= 'A') && ((x) <= 'Z'))
#define IS_ALPHABETIC(x) ((IS_LOWER_CASE(x)) || (IS_UPPER_CASE(x)))

#define IS_DIGIT(x) (((x) >= '0') && ((x) <= '9'))
#define IS_SPECIAL(x) (!(IS_DIGIT(x)) && !(IS_ALPHABETIC(x)))

int main(void) {
  printf("%c: %i\n", 'a', IS_SPECIAL('a'));
  printf("%c: %i\n", '!', IS_SPECIAL('!'));

  return 0;
}
