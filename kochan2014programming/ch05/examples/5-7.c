/* program to categorize a single character that is entered at the
terminal */

#include <stdio.h>

int main(void) {
  char inputC;

  printf("Enter a single charcter:\n");
  scanf("%c", &inputC);

  if((inputC >= 'a' && inputC <= 'z') || (inputC >= 'A' && inputC <= 'Z')) {
    printf("It's an alphabetic character.\n");
  }
  else if(inputC >= '0' && inputC <= '9') {
    printf("It's a digit.\n");
  }
  else {
    printf("It's a special character.\n");
  }

  return 0;
}
