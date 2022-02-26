#include <stdio.h>
#include <stdbool.h>

/* forward declaration(s) */
int prime(int);

int main(void) {
  printf("Prime? 2: %d\n", prime(2));
  printf("Prime? 7: %d\n", prime(7));
  printf("Prime? 10: %d\n", prime(10));

  return 0;
}

int prime(int num) {
  auto int i;
  auto bool isPrime;
  isPrime = true;

  for(i = 3; i < num; i += 2) {
    if(num % i == 0) {
      isPrime = false;
      break;
    }
  }

  if(isPrime) {
    return 1;
  }
  else {
    return 0;
  }
}
