#include <algorithm>
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
}
