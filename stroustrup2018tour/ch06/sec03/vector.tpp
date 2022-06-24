#include <iostream>
#include <list>
#include <stdexcept>

using std::cout;

template<typename T>
Vector<T>::Vector(int s) {
  if(s < 0) {
    throw std::length_error("size must be greater than or equal to zero");
  }

  elems_ = new T[s];
  size_ = s;
}

template<typename T> T&
Vector<T>::operator[](int i) {
  if(i < 0 || i >= size_) {
    throw std::out_of_range("Vector::operator[]: out of range access\n");
  }

  return elems_[i];
}

template<typename T> const T&
Vector<T>::operator[](int i) const {
  if (i < 0 || i >= size_) {
    throw std::out_of_range("Vector::operator[]: out of range access\n");
  }

  return elems_[i];
}

template<typename T>
T* Vector<T>::begin() const {
  return size_ ? &elems_[0] : nullptr;
}

template<typename T>
T* Vector<T>::end() const {
  return size_ ? &elems_[0] + size_ : nullptr;
}

template<typename T>
T* begin(const Vector<T>& v) {
  return v.size() ? &v[0] : nullptr;
}

template<typename T>
T* end(const Vector<T>& v) {
  return v.size() ? &v[0] + v.size() : nullptr;
}
