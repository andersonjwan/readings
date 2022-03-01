#include "vector.h"

Vector::Vector(int s) {
  elems_ = new double[s];
  size_ = s;
}

double&
Vector::operator[](int i) {
  return elems_[i];
}

int
Vector::size() {
  return size_;
}
