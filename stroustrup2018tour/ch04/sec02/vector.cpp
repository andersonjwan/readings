#include <iostream>
#include <stdexcept>

using std::cout;

class Vector {
private:
  double *elems_;
  int size_;

  int count_;

public:
  // constructors
  Vector(int s);
  Vector(std::initializer_list<double>);

  // deconstructor
  ~Vector(void);

  // capacity
  int size() const;

  // access
  double& operator[](int i);

  // modifiers
  void push_back(double);
};

Vector::Vector(int s) {
  if(s < 0) {
    throw std::length_error{"vector length must be >= 0"};
  }

  elems_ = new double[s];
  for(int i = 0; i < s; ++i) {
    elems_[i] = 0;
  }

  size_ = s;
  count_ = 0;
}

Vector::Vector(std::initializer_list<double> lst)
  : Vector(static_cast<int>(lst.size())) {
  std::copy(lst.begin(), lst.end(), elems_);
}

Vector::~Vector(void) {
  delete[] elems_;
  cout << "Vector deconstructed...\n";
}

int
Vector::size(void) const {
  return size_;
}

double&
Vector::operator[](int i) {
  if (i < 0 || i > size_) {
    throw std::out_of_range{"incorrect index for vector size"};
  }

  return elems_[i];
}

void
Vector::push_back(double d) {
  if(count_ >= size_) {
    throw std::out_of_range("cannot add element: vector at capacity");
  }

  elems_[count_] = d;
  ++count_;
}

Vector
read(std::istream& is, int sz) {
  Vector v(sz);
  for(double d; is >> d;) {
    v.push_back(d);
  }

  return v;
}

int
main(void) {
  Vector v1(10);
  v1[2] = 27;

  {
    Vector v2(2 * 10);
    cout << "v1.size(): " << v1.size() << "\n";
    cout << "v2.size(): " << v2.size() << "\n";
  }

  cout << "v1.size(): " << v1.size() << "\n";

  Vector v3(20);
  for(int i = 0; i < v3.size(); ++i) {
    v3.push_back(i);
  }

  // v3.push_back(5);

  Vector v4 = read(std::cin, 5);
  cout << "v4.size(): " << v4.size() << "\n";
  cout << "v4[3]: " << v4[3] << "\n";

  Vector v5 = {1, 2, 3};
  cout << "v5[2]: " << v5[2] << "\n";

  Vector v6 = 8;
  cout << "v6.size: " << v6.size() << "\n"; // valid, but not intended (see Section 5.1.2)
}
