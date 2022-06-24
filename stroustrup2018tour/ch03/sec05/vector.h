class Vector {
public:
  Vector(int s);

  double& operator[](int i);

  double SumTwo(int i1, int i2) noexcept;
  double DoubleIt(int i);
  int size();

private:
  double *elems_;
  int size_;
};
