#include <iostream>
#include <list>
#include <string>

using std::list;

struct Entry {
  std::string name;
  int number;
};

std::ostream&
operator<<(std::ostream& os, const Entry& entry) {
  os << "{\"" << entry.name << "\" , " << entry.number << "}";
  return os;
}

int
lookupNumber(const std::string& s, const list<Entry>& book) {
  for(const auto& x : book) {
    if(x.name == s) {
      return x.number;
    }
  }

  return 0;
}

int
main() {
  list<Entry> book = {
    {"David Hume", 12345},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  std::cout << "Karl Popper's number is... " << lookupNumber("Karl Popper", book) << "\n";
}
