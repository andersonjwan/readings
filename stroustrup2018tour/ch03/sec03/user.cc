import Vector;

#include <cmath>
#include <iostream>

using std::cout;

double
SqrtSum(Vector& v) {
  double sum = 0;

  for(int i = 0; i < v.size(); ++i) {
    sum += std::sqrt(v[i]);
  }

  return sum;
}

int
main(void) {
  Vector v(5);

  for(int i = 0; i < v.size(); ++i) {
    v[i] = 4;
  }

  double sqsum = SqrtSum(v);
  cout << "Answer: " << sqsum << "\n";
}
