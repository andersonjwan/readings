#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T>
class Vector {
private:
  T* elems_;
  int size_;

public:
  explicit Vector(int s);
  ~Vector() { delete[] elems_; }

  // copy operations
  // Vector(const Vector& v);
  // Vector& operator=(const Vector& v);

  // move operations
  // Vector(Vector&& v);
  // Vector& operator=(Vector&& v);

  T& operator[](int i);
  const T& operator[](int i) const;
  int size() const { return size_; }
};

#include "vector.tpp"

#endif
