#include <iostream>
#include <complex>

using namespace std;

void
unary_minus(double x) {
  cout << "-x: " << -x << "\n";
}

void
unary_plus(unsigned short x) {
  cout << "sizeof(x): " << sizeof(x) << ": ";
  cout << "x is an unsigned integer\n";
}

void
unary_plus(int x) {
  cout << "sizeof(x): " << sizeof(x) << ": ";
  cout << "x is a signed integer (i.e., an int)\n";
}

void
type_conversions(double x, int y) {
  double sum = x + y;
  int product = x * y;

  cout << "x + y: " << sum << "\n";
  cout << "x * y: " << product << "\n";
}

int
main(void) {
  cout << "Floating (3e-2): " << 3e-2 << "\n";
  cout << "Integer (42): " << 42 << "\n";
  cout << "Binary (0b10): " << 0b10 << "\n";
  cout << "Hexadecimal (0x10): " << 0x10 << "\n";
  cout << "Octal (0040): " << 0040 << "\n";

  type_conversions(2.2, 3);

  // unary operators
  unary_minus(-3);

  unsigned short x1 = 7;
  unary_plus(x1);
  unary_plus(+x1);

  // initialization types
  double d1 = 2.3;
  double d2 {2.5};

  complex<double> z1 = 1;
  complex<double> z2 = {d1, d2};
  complex<double> z3 {d1, d2};   // if using curly braces, equal not necessary

  int x2 = 7.8;  // valid
  // int x3 = {7.8} // invalid

  auto c = 'x';
  auto n = 5;

  cout << "sizeof(c): " << sizeof(c) << "\n";
  cout << "sizeof(n): " << sizeof(n) << "\n";
}
