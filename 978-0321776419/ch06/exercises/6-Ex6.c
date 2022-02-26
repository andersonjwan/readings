#include <stdio.h>

int main(void) {
  int term, fib_n, i = 2, fib_0 = 0, fib_1 = 1;

  /* prompt user for Nth fibonacci value */
  printf("Please enter the nth term of interest: \n");
  scanf("%d", &term);

  printf("\n");
  if(term == 0) {
    printf("%d\n", fib_0);
  }
  else if(term == 1) {
    printf("%d\n", fib_1);
  }
  else {
    printf("%d\n%d\n", fib_0, fib_1);

    while(i <= term) {
      fib_n = fib_0 + fib_1;
      printf("%d\n", fib_n);

      fib_0 = fib_1;
      fib_1 = fib_n;
      ++i;
    }
  }

  return 0;
}
