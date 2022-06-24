#include <stdio.h>

/* forward declaration(s) */
void concat(char [], const char [], int, const char [], int);

int main(void) {

  const char s1[5] = {'T', 'e', 's', 't', ' '};
  const char s2[6] = {'w', 'o', 'r', 'k', 's', '.'};
  char s3[5 + 6];
  int i;

  concat(s3, s1, 5, s2, 6);

  for(i = 0; i < (5 + 6); ++i) {
    printf("%c", s3[i]);
  }

  printf("\n");
  return 0;
}

void concat(char result[], const char str1[], const int n1,
            const char str2[], const int n2) {
  int i, j;

  // copy str1 to result
  for(i = 0; i < n1; ++i) {
    result[i] = str1[i];
  }

  // copy str2 to result
  for(j = 0; j < n2; ++j) {
    result[n1 + j] = str2[j];
  }
}
