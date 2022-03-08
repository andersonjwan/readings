#include <iostream>
#include <istream>

void
hello() {
  std::cout << "Please enter your name...\n>>>";

  std::string s;
  std::cin >> s;

  std::cout << "Hello, " << s << "!\n";
}

void
hello_line() {
  std::cout << "Please enter your full name...\n";

  std::string s;
  std::getline(std::cin, s);

  std::cout << "Hello, " << s << "!\n";
}

int
main() {
  int i;
  double d;

  // std::cin >> i >> d;

  // hello();
  hello_line();
}
