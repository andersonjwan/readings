#include <cmath>
#include <iostream>
#include <string>

using std::cout;

namespace MyNumbers {
  class Complex {
  public:
    Complex(double r, double i);

    double real() const;
    double imag() const;

    double Magnitude() const;
    std::string ToString() const;
    static Complex Sqrt(const Complex& cnum);
  private:
    double real_;
    double imag_;
  };

  Complex::Complex(double r, double i) {
    real_ = r;
    imag_ = i;
  }

  double
  Complex::real() const {
    return real_;
  }

  double
  Complex::imag() const {
    return imag_;
  }

  double
  Complex::Magnitude() const {
    return std::sqrt((real_ * real_) + (imag_ * imag_));
  }

  std::string
  Complex::ToString() const {
    return std::to_string(real_) + " + " + std::to_string(imag_);
  }

  Complex
  Complex::Sqrt(const Complex& cnum) {
    double r = std::sqrt((cnum.Magnitude() + cnum.real()) / 2);
    double i = std::sqrt((cnum.Magnitude() - cnum.real()) / 2);

    if(cnum.imag() < 0) {
      return Complex(r, -i);
    } else {
      return Complex(r, i);
    }
  }

  // defines a separate main
  int main(void);
}

int
MyNumbers::main(void) {
  Complex z1(3, 4);
  auto sqz1 = MyNumbers::Complex::Sqrt(z1);
  cout << "sqrt(3 + 4i) = " << sqz1.ToString() << "\n";

  Complex z2(0, -1);
  auto sqz2 = MyNumbers::Complex::Sqrt(z2);
  cout << "sqrt(0 + -i) = " << sqz2.ToString() << "\n";

  Complex z3(1, 2);
  auto sqz3 = MyNumbers::Complex::Sqrt(z3);
  cout << "sqrt(1 + 2i) = " << sqz3.ToString() << "\n";

  return 0;
}

int
main(void) {
  return MyNumbers::main();
}
