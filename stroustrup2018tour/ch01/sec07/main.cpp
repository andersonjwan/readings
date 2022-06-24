#include <iostream>

using std::cout;

void
modify(int &x) {
  x = 1;
}

int
main(void) {
  int nums[] = {0, 1, 2, 3, 4, 5};

  cout << "nums:";
  for(int i = 0; i < 6; ++i) {
    cout << " " << nums[i];
  }

  cout << "\nnums:";
  for(auto i = 0; i < 6; ++i) {
    cout << " " << nums[i];
  }

  cout << "\nnums:";
  for(int n : nums) {
    cout << " " << n;
  }

  cout << "\nnums:";
  for(auto n : nums) {
    cout << " " << n;
  }

  cout << "\n";

  int x = 1;
  int *px = &x;
  int &rx = x;

  cout << "x: " << x << "\n";
  cout << "px: " << px << "\n";
  cout << "*px: " << *px << "\n";
  cout << "rx: " << rx << "\n";

  rx = 7;
  cout << "x: " << x << "\n";
  cout << "px: " << px << "\n";
  cout << "*px: " << *px << "\n";
  cout << "rx: " << rx << "\n";

  int i = 1;
  int j = 2;

  int& iref = i;
  int& jref = j;

  cout << "i (before): " << i << "\n";
  cout << "j (before): " << j << "\n";
  cout << "iref (before): " << iref << "\n";
  cout << "jref (before): " << jref << "\n";

  i = 11;
  j = 12;

  cout << "i (after): " << i << "\n";
  cout << "j (after): " << j << "\n";
  cout << "iref (after): " << iref << "\n";
  cout << "jref (after): " << jref << "\n";

  iref = j; // reassigns the lvalue to the rvalue of j (i.e., 12)

  cout << "i (after, after): " << i << "\n";
  cout << "j (after, after): " << j << "\n";
  cout << "iref (after, after): " << iref << "\n";
  cout << "jref (after, after): " << jref << "\n";

  char word[6] = "12345";
  char* pnums = word;

  while(*pnums) {
    cout << *pnums << "... ";
    ++(pnums);
  }
  cout << "\n";
}
