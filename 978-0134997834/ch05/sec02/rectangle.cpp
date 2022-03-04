#include <iostream>
#include <stdexcept>
#include <vector>

using std::cout;

class Point {
public:
  Point(int x, int y) : x_{x}, y_{y} {}

  std::string ToString() {
    return "(" + std::to_string(x_) + ", " + std::to_string(y_) + ")";
  }

private:
  int x_;
  int y_;
};

class Vector {
public:
  explicit Vector(int s)
    : size_{s}, elems_{new double[s]} {}

  explicit Vector(int s1, int s2)
    : size_{s1}, elems_{new double[s1]} {
    cout << "s2: " << s2 << "\n";
  }

  // copy constructor/assignment
  Vector(const Vector& v);
  Vector& operator=(const Vector& v);

  ~Vector() { delete[] elems_; }

  int size() const {
    return size_;
  }

  double& operator[](int i);
  const double& operator[](int i) const;

  std::string ToString();

private:
  int size_ = 0;
  double *elems_ = nullptr;

};

Vector::Vector(const Vector& v)
  : size_{v.size()}, elems_{new double[v.size()]} {
  for(int i = 0; i < v.size(); ++i) {
    elems_[i] = v[i];
  }
}

Vector&
Vector::operator=(const Vector& v) {
  double *p = new double[v.size()];

  for(int i = 0; i < v.size(); ++i) {
    p[i] = v[i];
  }

  size_ = v.size();

  delete elems_;
  elems_ = p;

  return *this;
}

double&
Vector::operator[](int i) {
  return elems_[i];
}

const double&
Vector::operator[](int i) const {
  return elems_[i];
}

std::string
Vector::ToString() {
  std::string s = "";

  for(int i = 0; i < size_; ++i) {
    s += std::to_string(elems_[i]) + ", ";
  }

  return s;
}

class Shape {
public:
  Shape() {};

  // deleted functions
  Shape(const Shape&) = delete;            // copy constructor
  Shape& operator=(const Shape&) = delete; // copy assignment
};

class Rectangle {
public:
  // constructors
  Rectangle();
  Rectangle(const std::initializer_list<Point>);

  // copy/move constructor
  Rectangle(const Rectangle&); // copy
  //Rectangle(Rectangle&&);      // move

  // copy/move assignment
  //Rectangle& operator=(const Rectangle&); // copy
  //Rectangle& operator=(Rectangle&&);      // move

  Point& operator[](int i);

  std::string ToString();
private:
  std::vector<Point> points_;
};

Rectangle::Rectangle() {
  for(int i = 0; i < 4; ++i) {
    points_.push_back(Point(0, 0));
  }
}

Rectangle::Rectangle(const std::initializer_list<Point> list) {
  if(list.size() != 4) {
    throw std::length_error("four Point's must be provided");
  }

  for(auto p : list) {
    points_.push_back(p);
  }
}

Rectangle::Rectangle(const Rectangle& r) {
  for(int i = 0; i < 4; ++i) {
    points_.push_back(Point(-1, -1));
  }
}

Point&
Rectangle::operator[](int i) {
  return points_[i];
}

std::string
Rectangle::ToString() {
  std::string s = "";

  for(auto p : points_) {
    s += " " + p.ToString();
  }

  return s;
}

int
main(void) {
  Shape s1;
  Shape s2;

  // s1 = s2; // invalid, cannot use deleted function

  Rectangle r1 = {Point(0, 0), Point(1, 0), Point(1, 1), Point(0, 1)};
  cout << "R1: " << r1.ToString() << "\n";

  Rectangle r2(r1);
  cout << "R1: " << r1.ToString() << "\n";
  cout << "R2: " << r2.ToString() << "\n";

  Rectangle r3 = r2;
  cout << "R1: " << r1.ToString() << "\n";
  cout << "R2: " << r2.ToString() << "\n";
  cout << "R3: " << r3.ToString() << "\n";

  Rectangle r4;
  cout << "R1: " << r1.ToString() << "\n";
  cout << "R2: " << r2.ToString() << "\n";
  cout << "R3: " << r3.ToString() << "\n";
  cout << "R4: " << r4.ToString() << "\n";

  Vector v1(8);
  // Vector v2 = 9; // invalid, due to _explicit specifier_ on constructor
  // Vector v2 = {1, 2}; // invalid, due to _explicit specifier_ on constructor

  Vector v2(1, 2);

  Vector v3(3);
  v3[0] = 1;
  v3[1] = 2;
  v3[2] = 7;
  cout << "v3: " << v3.ToString() << "\n";
  cout << "===\n";

  Vector v4(v3);
  cout << "v3: " << v3.ToString() << "\n";
  cout << "v4: " << v4.ToString() << "\n";
  cout << "===\n";

  v3[1] = 7;
  cout << "v3: " << v3.ToString() << "\n";
  cout << "v4: " << v4.ToString() << "\n";
  cout << "===\n";

  v4 = v3;
  cout << "v3: " << v3.ToString() << "\n";
  cout << "v4: " << v4.ToString() << "\n";
  cout << "===\n";

  v3[0] = 53;
  cout << "v3: " << v3.ToString() << "\n";
  cout << "v4: " << v4.ToString() << "\n";
  cout << "===\n";
}
