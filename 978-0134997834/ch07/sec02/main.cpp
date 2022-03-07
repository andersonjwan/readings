#include <iostream>
#include <iterator>
#include <string>

using std::cout;

template<typename T>
concept EqualityComparable =
  requires(T a, T b) {
  { a == b } -> std::same_as<bool>;
  { a != b } -> std::same_as<bool>;
};

// default template arguments
template<typename T1, typename T2 = T1>
concept EqualityComparableTwo =
  requires(T1 a, T2 b) {
  { a == b } -> std::same_as<bool>;
  { a != b } -> std::same_as<bool>;
  { b == a } -> std::same_as<bool>;
  { b != a } -> std::same_as<bool>;
};

// template<typename T>
// concept Sequence = requires(T a) {
//   typename T::value_type;
//   typename T::iterator_type;

//   { begin(a) } -> T::iterator_type;
//   { end(a) } -> T::iterator_type;

//   requires std::same_as<T::value_type, T::value_type<T::iterator_type>>;
//   requires std::input_iterator<iterator_type<T>>;
// };

template<typename... T>
int sum(T... v) {
  return (v + ... + 0);
}

int
main(void) {
  static_assert(EqualityComparable<int>);

  struct S {
    int a;
  };

  // static_assert(EqualityComparable<S>); // INVALID: struct does not
  // inherently support comparison

  static_assert(EqualityComparableTwo<int, double>);
  static_assert(EqualityComparableTwo<int>);
  // static_assert(EqualityComparableTwo<int, std::string>); // INVALID: cannot
  // compare an std::string with an int

  cout << std::to_string(sum(1, 2, 3, 4, 5)) << "\n";
}

// template<typename S, typename N>
// requires Arithmetic<Value_type<S>, N>
// N sum(S s, N n) {
//   for(const auto& x : s) {
//     n += x;
//   }

//   return n
// }
