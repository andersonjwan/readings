#include <iostream>
#include <sstream>

template<typename T = std::string, typename S = std::string>
T to(S arg) {
  std::stringstream interp;
  T result;

  if(!(interp << arg) || !(interp >> result) || !(interp >> std::ws).eof()) {
    throw std::runtime_error("to<>() failed");
  }

  return result;
}

int
main() {
  std::ostringstream oss;

  oss << "{temperature, " << std::scientific << 123.4567890 << "}";
  std::cout << oss.str() << "\n";

  auto x1 = to<std::string, double>(1.2);
  auto x2 = to<std::string>(1.2);
  auto x3 = to<>(1.2);
  auto x4 = to(1.2);
}
