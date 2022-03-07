#include <iostream>
#include <list>
#include <stdexcept>

#include "vector.hpp"

using std::cout;

void
print(const Vector<std::string>& vs) {
  for(int i = 0; i < vs.size(); ++i) {
    cout << "vs[" << i << "]: " << vs[i] << "\n";
  }
}

int
main(void) {
  Vector<char> vc(200);
  Vector<std::string> vs(17);
  Vector<std::list<int>> vl(45);

  vs[0] = "Hello";
  vs[1] = ",";
  vs[2] = "Template";
  vs[3] = "World!";

  print(vs);

  for(auto& s : vs) {
    cout << "frange: " << s << "\n";
  }
}
