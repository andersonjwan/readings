#include <list>
#include <string>
#include <vector>

#include "vector.hpp"

template<typename T>
class LessThan {
  const T val_;

public:
  LessThan(const T& v)
    : val_{v} {}

  bool operator()(const T& x) const {
    return x < val_;
  }
};

template<typename Sequence, typename Value>
Value sum(const Sequence& s, Value v) {
  for(auto x : s) {
    v += x;
  }

  return v;
}

template<typename C, typename P>
int count(const C& c, P p) {
  int count = 0;

  for(const auto& x : c) {
    if(p(x)) {
      ++count;
    }
  }

  return count;
}

void
example01(const Vector<int>& v, const std::list<std::string>& lst, int x,
	  const std::string& s) {
  cout << "number of values less than " << x << ": "
       << count(v, LessThan<int>(x)) << "\n";
  cout << "number of values less than " << s << ": "
       << count(lst, LessThan<std::string>(s)) << "\n";
}

template<typename C, typename O>
void forall(C& c, O op) {
  for(auto& x : c) {
    op(x);
  }
}

int
main(void) {
  Vector<int> V1(3);
  V1[0] = 1;
  V1[1] = 2;
  V1[2] = 3;

  std::list<double> l1 = {5, 76, 8};
  std::vector<double> v1 = {1, 2, 3};

  int V1_sum = sum(V1, 0);
  double l1_sum = sum(l1, 0.0);
  double v1_sum = sum(v1, 10.0);

  cout << "V1 sum: " << V1_sum << "\n";
  cout << "l1 sum: " << l1_sum << "\n";
  cout << "v1 sum: " << v1_sum << "\n";

  LessThan<int> lti(42);
  LessThan<std::string> lts1("backus");
  LessThan<std::string> lts2("naur");

  cout << lti(7) << "\n"
       << lts1("abc") << "\n"
       << lts2("yay") << "\n";

  Vector<int> vints(2);
  vints[0] = 7;
  vints[1] = 11;

  std::list<std::string> lst1 = {"abc", "hello", "backus"};
  example01(vints, lst1, 10, "dog");
}
