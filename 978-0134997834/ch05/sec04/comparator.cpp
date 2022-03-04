#include <iostream>

using std::cout;

namespace WrongComparator {
  class Number {
  public:
    Number(unsigned int n)
      : value_{n} { sign_ = false; }
    unsigned int value_;
    bool sign_;
  };

  bool operator==(const Number& n1, const Number& n2) {
    return n1.value_ != n2.value_;
  }

  bool operator!=(const Number& n1, const Number& n2) {
    return n1.value_ == n2.value_;
  }
}

int
main(void) {
  WrongComparator::Number n1(7);
  WrongComparator::Number n2(8);
  WrongComparator::Number n3(7);

  if(n1 == n2) {
    cout << "n1 does NOT equal n2\n";
  } else if(n1 != n2) {
    cout << "n1 DOES equal n2\n";
  }

  if(n1 == n3) {
    cout << "n1 does NOT equal n3\n";
  } else if(n1 != n3) {
    cout << "n1 DOES equal n3\n";
  }
}
