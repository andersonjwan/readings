#include <iostream>

using std::cout;

constexpr unsigned int
factorial(unsigned int num) {
  int fact = 1;

  for (unsigned int i = 1; i <= num; ++i) {
    fact = fact * i;
  }

  return fact;
}

unsigned int
add_one(const unsigned int* x) {
  return *x + 1;
}

int
main(void) {
  constexpr unsigned int x = 4;

  // x = add_one(&x); // invalid
  const unsigned int y = add_one(&x);     // valid, can be computed at runtime
  // constexpr unsigned int z = add_one(&x); // invalid, add_one is not constexpr

  unsigned int m = factorial(add_one(&x));
  cout << "factorial(4): " << factorial(x) << "\n";
  cout << "factorial(5): " << factorial(add_one(&x)) << "\n";
}
