#include <iostream>
#include <variant>

using std::cout;
using std::string;

enum Type {
  POINTER,
  NUMBER
};

struct Node{
  struct Node *left;
  struct Node *right;
};

struct Entry {
  string name;
  Type t;

  union Value {
    struct Node *p;
    int i;
  } v;
};

void
entry_print(const struct Entry& e) {
  if(e.t == POINTER) {
    cout << "Pointer: " << e.v.p << "\n";
  } else if(e.t == NUMBER) {
    cout << "Number: " << e.v.i << "\n";
  }
}

// variant usage
class Symbol {
private:
  string name;
  std::variant<struct Node*, int> v;

public:
  Symbol(struct Node *n) {
    v = n;
  }

  Symbol(int n) {
    v = n;
  }

  void print() {
    if(std::holds_alternative<struct Node*>(v)) {
      cout << "Symbol Pointer: " << std::get<struct Node *>(v) << "\n";
    } else if(std::holds_alternative<int>(v)) {
      cout << "Symbol Number: " << std::get<int>(v) << "\n";
    }
  }
};

int
main(void) {
  struct Entry e1;
  e1.name = "Entry #1";
  e1.t = POINTER;
  e1.v.p = new struct Node;

  entry_print(e1);

  struct Entry e2;
  e2.name = "Entry #2";
  e2.t = NUMBER;
  e2.v.i = 17;

  entry_print(e2);

  Symbol s1(new struct Node);
  Symbol s2(2500);

  s1.print();
  s2.print();
}
