#include <stdio.h>

/* forward declaration(s) */
void concat(char [], const char [], const char[]);

int main(void) {
  const char s1[] = "Test ";
  const char s2[] = "works.";
  char s3[20];

  concat(s3, s1, s2);

  printf("%s\n", s3);
  return 0;
}

void concat(char result[], const char str1[], const char str2[]) {
  /**
   * concat concatenates two character arrays appending
   * str2 to str1 and placing the result into result.
   *
   * @param result[]
   * @param str1[]
   * @param str2[]
   */

  int i, j;

  // copy str1 to result
  for(i = 0; str1[i] != '\0'; ++i) {
    result[i] = str1[i];
  }

  // copy str2 to result
  for(j = 0; str2[j] != '\0'; ++j) {
    result[i + j] = str2[j];
  }

  // terminate resultant string
  result[i + j] = '\0';
}
