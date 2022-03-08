#include <iostream>
#include <istream>
#include <ostream>
#include <string>

struct Entry {
  std::string name;
  int number;
};

std::ostream& operator<<(std::ostream& os, const Entry& e) {
  return os << "{\"" << e.name << "\"," << e.number << "}";
}

std::istream& operator>>(std::istream& is, Entry& e) {
  char c1;
  char c2;

  if(is >> c1 && c1 == '{' && is >> c2 && c2 == '"') {
    std::string name;
    while(is.get(c1) && c1 != '"') {
      name += c1;
    }

    if(is >> c1 && c1 == ',') {
      int number = 0;

      if(is >> number >> c1 && c1 == '}') {
	e = {name, number};
	return is;
      }
    }
  }

  is.setstate(std::ios_base::failbit);
  return is;
}

int
main() {
  Entry e;
  while(std::cin >> e && !std::cin.fail()) {
    std::cout << e << "\n";
  }
  std::cin.clear();
  std::cin.unget();

  std::string s;
  std::cin >> s;

  std::cout << "error: cannot convert the following to an entry: " << s << "\n";
}
