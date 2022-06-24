#include <iostream>
#include <istream>
#include <string>
#include <vector>

std::vector<int> read_integers(std::istream& is, const std::string& terminator) {
  std::vector<int> res;

  for(int i; is >> i;) {
    res.push_back(i);
  }

  if(is.eof()) {
    std::cout << "end-of-file reached...\n";
    return res;
  }

  if(is.fail()) {
    std::cout << "failure...\n";
    is.clear();
    is.unget();

    std::string s;
    if(std::cin >> s && s == terminator) {
      std::cout << "found terminator...\n";
      return res;
    }

    std::cin.setstate(std::ios_base::failbit);
  }

  return res;
}

int
main() {
  auto v = read_integers(std::cin, "stop");
}
