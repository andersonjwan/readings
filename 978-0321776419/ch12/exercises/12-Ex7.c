#include <stdio.h>

#define IS_LOWER_CASE(x) (((x) >= 'a') && ((x) <= 'z'))
#define IS_UPPER_CASE(x) (((x) >= 'A') && ((x) <= 'Z'))
#define IS_ALPHABETIC(x) ((IS_LOWER_CASE(x)) || (IS_UPPER_CASE(x)))

int main(void) {
  char c1 = '!', c2 = 'b';

  if(IS_ALPHABETIC(c1)) {
    printf("%c is alphabetic.\n", c1);
  }
  else {
    printf("%c is not alphabetic.\n", c1);
  }

  if(IS_ALPHABETIC(c2)) {
    printf("%c is alphabetic.\n", c2);
  }
  else {
    printf("%c is not alphabetic.\n", c2);
  }

  return 0;
}
