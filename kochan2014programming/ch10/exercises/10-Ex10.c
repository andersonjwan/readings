#include <stdio.h>

int compareStrings(char const *, char const *);

int main(void) {
  printf("apple vs. banana: %i\n", compareStrings("apple", "banana"));
  printf("apples vs. apple: %i\n", compareStrings("apples", "apple"));
  return 0;
}

int compareStrings(char const * s1, char const * s2) {
  int i = 0, answer;

  while(*(s1 + i) == *(s2 + i) && *(s1 + i) != '\0' && *(s2 + i) != '\0') {
    ++i;
  }

  if(*(s1 + i) < *(s2 + i)) {
    answer = -1;
  }
  else if(*(s1 + i) > *(s2 + i)) {
    answer = 1;
  }
  else {
    answer = 0;
  }

  return answer;
}
