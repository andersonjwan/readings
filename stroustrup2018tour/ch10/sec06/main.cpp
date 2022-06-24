#include <iostream>

int
main() {
  constexpr double d = 1234.567;

  std::cout << d << "; "
	    << std::scientific << d << "; "
	    << std::hexfloat << d << "; "
	    << std::fixed << d << "; "
	    << std::defaultfloat << d << "\n";

  std::streamsize _size = std::cout.precision();

  std::cout.precision(10);
  std::cout << d << "\n";

  std::cout.precision(2);
  std::cout << d << "\n";

  std::cout.precision(4);
  std::cout << d << "\n";

  std::cout.precision(5);
  std::cout << d << "\n";

  std::cout.precision(_size);
  std::cout << d << "\n";
}
