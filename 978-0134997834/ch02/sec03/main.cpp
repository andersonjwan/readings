#include <iostream>

using std::cin;
using std::cout;

/* classes */
class Vector {
public:
  Vector(int s) : elems{new double [s]}, sz{s} {}

  double& operator[](int i) {
    return elems[i];
  }

  int size() {
    return sz;
  }
private:
  double* elems;
  int sz;
};

/* structures */
struct sVector {
  sVector(int s) : elems{new double [s]}, sz{s} {}

  double& operator[](int i) {
    return elems[i];
  }

  int size() {
    return sz;
  }

private:
  double* elems;
  int sz;
};

class A {
  std::string s;
};

struct B {
  std::string s;
};

int
main(void) {
  /* class usage */
  Vector v(5);

  for(int i = 0; i < v.size(); ++i) {
    cin >> v[i];
  }

  double sum = 0;

  for(int i = 0; i < v.size(); ++i) {
    sum += v[i];
  }

  cout << "Sum: " << sum << "\n";
  //  cout << "v[1]: " << v.elems[1] << "\n";

  /* structure usage */
  struct sVector sv(5);

  for(int i = 0; i < sv.size(); ++i) {
    cin >> sv[i];
  }

  double ssum = 0;

  for(int i = 0; i < sv.size(); ++i) {
    ssum += sv[i];
  }

  cout << "Sum: " << ssum << "\n";
  //  cout << "sv[1]: " << sv.elems[1] << "\n";

  A a;
  B b;

  //  a.s = "Hello";
  b.s = "Hello";
}
