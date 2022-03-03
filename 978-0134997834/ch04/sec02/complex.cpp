#include <iostream>

using std::cout;

namespace MyNumbers {
  class Complex {
  private:
    double real_;
    double imag_;

  public:
    Complex(double r, double i);
    Complex(double r);
    Complex();

    double real() const;
    double imag() const;

    void real(double r);
    void imag(double i);

    // overloaded operators
    Complex& operator+=(const Complex& a);
    Complex& operator-=(const Complex& a);
    Complex& operator*=(const Complex& a);
    Complex& operator/=(const Complex& a);

    std::string ToString();
  };

  Complex::Complex(double r, double i) {
    real_ = r;
    imag_ = i;
  }

  Complex::Complex(double r) {
    real_ = r;
    imag_ = 0;
  }

  Complex::Complex() {
    real_ = 0;
    imag_ = 0;
  }

  double
  Complex::real() const {
    return real_;
  }

  double
  Complex::imag() const {
    return imag_;
  }

  void
  Complex::real(double r) {
    real_ = r;
  }

  void
  Complex::imag(double i) {
    imag_ = i;
  }

  Complex&
  Complex::operator+=(const Complex& a) {
    real_ += a.real();
    imag_ += a.imag();

    return *this;
  }

  Complex&
  Complex::operator-=(const Complex& a) {
    real_ -= a.real();
    imag_ -= a.imag();

    return *this;
  }

  Complex&
  Complex::operator*=(const Complex& a) {
    double r = real_ * a.real() - imag_ * a.imag();
    double i = real_ * a.imag() + imag_ * a.real();

    real_ = r;
    imag_ = i;

    return *this;
  }

  Complex&
  Complex::operator/=(const Complex& a) {
    double r = ((real_ * a.real()) + (imag_ * a.imag())) / ((a.real() * a.real()) + (a.imag() * a.imag()));
    double i = ((imag_ * a.real()) - (real_ * a.imag())) / ((a.real() * a.real()) + (a.imag() * a.imag()));

    real_ = r;
    imag_ = i;

    return *this;
  }

  std::string
  Complex::ToString() {
    return "{ " + std::to_string(real_) + " , " + std::to_string(imag_) + "}";
  }

  Complex operator+(Complex a, Complex b) { return a += b; }
  Complex operator-(Complex a, Complex b) { return a -= b; }
  Complex operator-(Complex a) { return {-a.real(), -a.imag()}; }
  Complex operator*(Complex a, Complex b) { return a *= b; }
  Complex operator/(Complex a, Complex b) { return a /= b; }

  bool operator==(Complex a, Complex b) { return a.real() == b.real() && a.imag() == b.imag(); }
  bool operator!=(Complex a, Complex b) { return !(a == b); }
}

int
main(void) {
  MyNumbers::Complex z1(3, 2);
  MyNumbers::Complex z2(1, 7);

  MyNumbers::Complex z3;
  z3 = z1 * z2;

  cout << "z1 * z2: " << z1.ToString() << "\n";
  cout << "z1 * z2: " << z3.ToString() << "\n";

  MyNumbers::Complex z4(3, 5);
  MyNumbers::Complex z5(-2, 2);

  cout << "z4 / z5: " << (z4 / z5).ToString() << "\n";
}
