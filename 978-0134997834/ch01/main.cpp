#include <iostream>

using std::cin;
using std::cout;
using std::string;

unsigned int
factorial(int n) {
  unsigned int fact = 1;

  for(auto i = n; i > 0; --i) {
    fact = fact * i;
  }

  return fact;
}

bool
isequal(int num1, int num2) {
  return num1 == num2;
}

string
reverse(string str) {
  string reversed = "";

  for(auto c : str) {
    reversed.insert(reversed.begin(), c);
  }

  return reversed;
}

void
prompt_factorial(void) {
  cout << "Please enter a positive integer...\n";
  cout << ">>> ";

  int num;
  cin >> num;

  if(num < 0) {
    cout << "Uh-oh! You must provide a positive number. Please try again!\n";
  } else {
    cout << "Result: " << factorial(num) << "\n";
  }
}

void
prompt_equivalent(void) {
  cout << "Please enter the first number to compare...\n";
  cout << ">>> ";

  int num1;
  cin >> num1;

  cout << "Please enter the second number to compare with...\n";
  cout << ">>> ";

  int num2;
  cin >> num2;

  if(isequal(num1, num2)) {
    cout << "TRUE! " << num1 << " == " << num2 << "\n";
  } else {
    cout << "FALSE! " << num1 << " != " << num2 << "\n";
  }
}

void
prompt_reverse(void) {
  cout << "Enter a word to reverse...\n";
  cout << ">>> ";

  string word;
  cin >> word;

  cout << "Original: " << word << "\n";
  cout << "Reversed: " << reverse(word) << "\n";
}

int
main(void) {
  cout << "Please select a service...\n";
  cout << "\t1. Calculate the factorial of a number\n";
  cout << "\t2. Check the equivalency of two numbers\n";
  cout << "\t3. Reverse a word\n";

  int selection;
  cout << ">>> ";
  cin >> selection;

  switch(selection) {
  case 1: prompt_factorial();  break;
  case 2: prompt_equivalent(); break;
  case 3: prompt_reverse();    break;
  default:
    cout << "Sorry, unknown selection. Please try again!\n";
    break;
  }
}
