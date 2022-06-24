#include <iostream>
#include <regex>
#include <string>

void
example943() {
  std::string input = "aa as; asd ++e^asdf asdfg";
  std::regex r(R"(\s+(\w+))");

  for(std::sregex_iterator iter(input.begin(), input.end(), r);
      iter != std::sregex_iterator(); ++iter) {
    std::cout << (*iter)[1] << "\n";
  }
}

int
main() {
  int lineno = 0;

  std::regex reg(R"(\w{2}\s*\d{5}(-\d{4})?)");

  for(std::string line; getline(std::cin, line); ) {
    ++lineno;

    std::smatch matches;
    if(std::regex_search(line, matches, reg)) {
      std::cout << lineno << ": " << matches[0] << "\n";
    }
  }

  example943();
}
