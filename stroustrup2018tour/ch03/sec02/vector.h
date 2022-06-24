class Vector {
public:
  Vector(int s);

  double& operator[](int i);
  int size();

private:
  double *elems_;
  int size_;
};
