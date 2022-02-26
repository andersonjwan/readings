#include <stdio.h>

/* forward declaration(s) */

int main(void) {
  char str1[81], str2[81], str3[81];

  printf("Enter text:\n");
  scanf("%s%s%s", str1, str2, str3);

  printf("\nstr1 = %s\nstr2 = %s\nstr3 = %s\n", str1, str2, str3);
  return 0;
}
