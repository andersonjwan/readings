#include <string>
#include <vector>

template<typename T>
using val_type = typename T::val_type;

template<typename C>
void alg(C& c) {
  std::vector<val_type<C>> v;
}

template<typename K, typename V>
class Map {
  // some class definition
};

template<typename V>
using StringMap = Map<std::string, V>;

// compile-time conditionals
// the selected/appropriate branch is instantiated at compile-time
template<typename T>
void update(T& target) {
  // ...
  if constexpr(std::is_pod<T>::value) {
    simple_and_fast(target);
  } else {
    slow_and_safe(target);
  }
}

int
main() {
  StringMap<int> m_int;
  StringMap<double> m_double;
}
