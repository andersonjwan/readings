#include <iostream>
#include <list>
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

class Container {
public:
  virtual ~Container() {}

  virtual double& operator[](int) = 0;
  virtual int size() const = 0;
};

class VectorContainer : public Container {
public:
  VectorContainer(int s) : v_(s) {}
  ~VectorContainer() {cout << "VectorContainer deconstructed...\n"; }

  int size() const override { return v_.size(); }
  double& operator[](int i) override { return v_[i]; }
private:
  Vector v_;
};

class ListContainer : public Container {
public:
  ListContainer() {}
  ListContainer(std::initializer_list<double> list) : list_{list} {}
  ~ListContainer() {}

  double& operator[](int i) override;
  int size() const override { return list_.size(); }

private:
  std::list<double> list_;
};

double&
ListContainer::operator[](int i) {
  cout << "accessing list...\n";
  for(auto& x : list_) {
    if(i == 0) {
      return x;
    }

    --i;
  }

  throw std::out_of_range("list container out-of-bounds");
}

void
printContainer(Container& c) {
  const int size = c.size();

  cout << "[";
  for(int i = 0; i < size; ++i) {
    cout << " " << c[i] << ",";
  }

  cout << "]\n";
}

int
main(void) {
  VectorContainer vc(5);

  for(int i = 0; i < vc.size(); ++i) {
    vc[i] = 2;
  }

  printContainer(vc);

  ListContainer lc = {1, 2, 3, 4, 5, 6, 7, 8, 9 };
  printContainer(lc);
}
