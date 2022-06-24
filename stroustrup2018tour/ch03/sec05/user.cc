#include <iostream>
#include <stdexcept>

#include "vector.h"

using std::cout;
using std::cerr;

int
main(void) {
  Vector v(5);

  for(int i = 0; i < v.size(); ++i) {
    v[i] = 2;
  }

  try {
    cout << "v[2]: " << v[2] << "\n";
    cout << "v[6]: " << v[6] << "\n";
  } catch(std::out_of_range& e) {
    cerr << e.what() << "\n";
  }

  cout << "v[1] + v[2]: " << v.SumTwo(1, 2) << "\n";
  // cout << "v[7] + v[5]: " << v.SumTwo(7, 5) << "\n";

  // try {
  //   Vector v(-27);
  // } catch(std::length_error& e) {
  //   cerr << e.what() << "\n";
  //   throw;
  // } catch(std::bad_alloc& e) {
  //   cerr << e.what() << "\n";
  //   std::terminate();
  // }

  // Vector v2(-28);

  cout << "v[2] * 2: " << v.DoubleIt(2) << "\n";
  cout << "v[7] * 2: " << v.DoubleIt(7) << "\n";
}
