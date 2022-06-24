#include <iostream>

using std::cout;

int
main(void) {
  int x = 0;

  if(auto n = x; n == 1) {
    cout << "1. n: " << n << "\n";
  } else if(auto m = n + 2; m == 2) {
    cout << "2. n: " << n << "\n";
    cout << "2. m: " << m << "\n";
  } else {
    cout << "3. n: " << n << "\n";
    cout << "3. m: " << m << "\n";
  }
}
