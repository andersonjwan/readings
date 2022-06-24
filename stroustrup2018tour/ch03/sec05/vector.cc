#include "vector.h"

#include <cassert>
#include <stdexcept>

Vector::Vector(int s) {
  if(s < 0) {
    throw std::length_error{"Vector constructor: negative size"};
  }

  elems_ = new double[s];
  size_ = s;
}

double&
Vector::operator[](int i) {
  if(i < 0 || i > size_) {
    throw std::out_of_range{"Vector::operator[]"};
  }
  return elems_[i];
}

double
Vector::SumTwo(int i1, int i2) noexcept {
  if(i1 < 0 || i1 > size_ || i2 < 0 || i2 > size_) {
    throw std::out_of_range{"error: cannot sum"};
  }

  return elems_[i1] + elems_[i2];
}

double
Vector::DoubleIt(int i) {
  assert(i >= 0 && i < size_);

  return elems_[i] * 2;
}

int
Vector::size() {
  return size_;
}
