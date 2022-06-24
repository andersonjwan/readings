#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <vector>

using std::list;
using std::vector;

struct Entry {
  std::string name;
  int number;
};

bool
operator<(const Entry& a, const Entry& b) {
  return a.name < b.name;
}

bool
operator==(const Entry& a, const Entry& b) {
  return a.name == b.name;
}

bool
operator==(const Entry& a, const std::string s) {
  return a.name == s;
}

void
adjust(vector<Entry>& v, list<Entry>& l) {
  sort(v.begin(), v.end());
  unique_copy(v.begin(), v.end(), l.begin());
}

list<Entry>
easyAdjust(vector<Entry>& v) {
  list<Entry> res;

  sort(v.begin(), v.end());
  unique_copy(v.begin(), v.end(), back_inserter(res));

  return res;
}

bool
hasName(const vector<Entry>& v, std::string name) {
  return find(v.begin(), v.end(), name) != v.end();
}

vector<std::string::iterator>
findAllChars(std::string& s, char c) {
  std::vector<std::string::iterator> res;

  for(auto iter = s.begin(); iter != s.end(); ++iter) {
    if(*iter == c) {
      res.push_back(iter);
    }
  }

  return res;
}

int
main() {
  vector<Entry> book = {
    {"David Hume", 12345},
    {"Karl Popper", 234567},
    {"Bertrand Arthur William Russell", 345678}
  };

  list<Entry> booklist(3);

  adjust(book, booklist);
  list<Entry> easylist = easyAdjust(book);

  if(hasName(book, "Karl Popper")) {
    std::cout << "NAME FOUND!\n";
  } else {
    std::cout << "NAME NOT FOUND!\n";
  }

  std::string s("Hello, World!");
  vector<std::string::iterator> chars = findAllChars(s, 'o');

  for(auto& x : chars) {
    std::cout << "found... " << *x << " at position " << x - s.begin() << "\n";
  }
}
