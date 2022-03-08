#include <iostream>
#include <map>
#include <string>

using std::map;

int
main() {
  map<std::string, int> book = {
    {"David Hume", 12345},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  std::cout << "David Hume's number is... " << book["David Hume"] << "\n";
  std::cout << "John Gus' number is... " << book["John Gus"] << "\n";
}
