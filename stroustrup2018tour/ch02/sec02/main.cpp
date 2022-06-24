#include <iostream>

using std::cin;
using std::cout;

/* structures */
struct Vector {
  int size;
  double *elems;
};

void
vector_init(Vector& v, int size) {
  v.elems = new double[size];
  v.size = size;
}

double
vector_sum(const Vector& v) {
  int sum = 0;

  for(int i = 0; i < v.size; ++i) {
    sum += v.elems[i];
  }

  return sum;
}

int
main(void) {
  Vector v1;
  vector_init(v1, 10);

  for(auto i = 0; i < v1.size; ++i) {
    cin >> v1.elems[i];
  }

  cout << "Sum: " << vector_sum(v1) << "\n";
}
