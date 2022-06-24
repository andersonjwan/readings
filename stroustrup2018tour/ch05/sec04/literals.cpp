#include <iostream>

using std::cout;

class Animal {
public:
  constexpr Animal(unsigned int age)
    : age_{age} {
    cout << "set age to ... " << age << "\n";
  }

private:
  unsigned int age_;
};

constexpr Animal operator"" _a(unsigned long long age) {
  return Animal(age);
}

int
main(void) {
  Animal a1 = 27_a;
}
