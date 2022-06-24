#include <iostream>
#include <vector>

using std::cout;
using std::vector;

int
sum(const vector<int>& v) {
  int sum = 0;

  for(const int i : v) {
    sum += i;
  }

  return sum;
}

void
modify(vector<int> v, vector<int>& rv) {
  v[1] = 99;
  rv[2] = 23;
}

// function with default argument value(s)
void
display(vector<int> v = {0, 0, 0}) {
  cout << "[";
  for(const auto i : v) {
    cout << " " << i;
  }
  cout << " ]\n";
}

int
main(void) {
  vector<int> v = {1, 2, 3};
  cout << "sum: " << sum(v) << "\n";

  cout << "BEFORE: " << v[1] << " " << v[2] << "\n";
  modify(v, v);
  cout << "AFTER: " << v[1] << " " << v[2] << "\n";

  display();
  display(v);
}
