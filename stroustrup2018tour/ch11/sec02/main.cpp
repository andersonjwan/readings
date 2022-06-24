#include <iostream>
#include <ostream>
#include <string>
#include <vector>

struct Entry {
  std::string name;
  int number;
};

std::ostream&
operator<<(std::ostream& os, const Entry& entry) {
  os << "{\"" << entry.name << "\" , " << entry.number << "}";
  return os;
}

void
print_entries(const std::vector<Entry>& book) {
  for(size_t i = 0; i < book.size(); ++i) {
    std::cout << book[i] << "\n";
  }

  // or

  for(const auto& x : book) {
    std::cout << x << "\n";
  }
}

int
main() {
  std::vector<Entry> phone_book = {
    {"David Hume", 12345},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  print_entries(phone_book);
}
