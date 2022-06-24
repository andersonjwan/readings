#include <iostream>

using namespace std;

void
print(int x) {
  cout << "Integer: " << x << "\n";
}

void
print(double x) {
  cout << "Double: " << x << "\n";
}

void
print(string x) {
  cout << "String: " << x << "\n";
}

// not allowed since a function type of string -> void exists
// void
// print(string x) {
//   cout << "String 2: " << x << "\n";
// }

int
main(void) {
  print(1);
  print(2.0);
  print("Hello, C++ World!");
}
