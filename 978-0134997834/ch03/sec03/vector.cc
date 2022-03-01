module;

export module Vector;

export class Vector {
public:
  Vector(int s);

  double& operator[](int i);
  int size() const;

private:
  double* elems_;
  int size_;
};

Vector::Vector(int s) {
  elems_ = new double[s];
  size_ = s;
}

double&
Vector::operator[](int i) {
  return elems_[i];
}

int
Vector::size() const {
  return size_;
}

export int size(const Vector& v) {
  return v.size();
}
