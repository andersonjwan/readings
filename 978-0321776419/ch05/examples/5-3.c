#include <stdio.h>

int main(void) {
  int numberTest, remainder;

  printf("Enter your number to be tested: ");
  scanf("%d", &numberTest);

  remainder = numberTest % 2;

  if(remainder == 0)
    printf("The number is even.\n");
  if(remainder != 0)
    printf("The number is odd.\n");

  return 0;
}
