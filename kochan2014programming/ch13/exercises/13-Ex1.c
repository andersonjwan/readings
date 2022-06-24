#include <stdio.h>

int FunctionPtr(void);

int main(void) {
  typedef int (* func_ptr_t) (void);

  func_ptr_t func_ptr = FunctionPtr;
  printf("%i\n", func_ptr());
  return 0;
}

int FunctionPtr(void) {
  return 5;
}
