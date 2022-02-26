#include <stdio.h>

int main(void) {
  int num, tempNum, numDigits, digit;

  printf("Please enter a number: ");
  scanf("%d", &num);
  tempNum = num;

  // count the number of digits
  numDigits = 0;
  do {
    numDigits += 1;
    tempNum /= 10;
  }
  while(tempNum != 0);

  while(numDigits != 0) {
    tempNum = num;

    for(int i = 1; i <= numDigits; ++i) {
      digit = tempNum % 10;
      tempNum /= 10;
    }

    switch(digit) {
    case 1:
      printf("one ");
      break;
    case 2:
      printf("two ");
      break;
    case 3:
      printf("three ");
      break;
    case 4:
      printf("four ");
      break;
    case 5:
      printf("five ");
      break;
    case 6:
      printf("six ");
      break;
    case 7:
      printf("seven ");
      break;
    case 8:
      printf("eight ");
      break;
    case 9:
      printf("nine ");
      break;
    case 0:
      printf("zero ");
      break;
    }

    numDigits -= 1;
  }

  printf("\n");
  return 0;
}
