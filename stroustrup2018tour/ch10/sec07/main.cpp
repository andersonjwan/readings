#include <fstream>

int
main() {
  std::ofstream ofs("output.txt");

  if(ofs) {
    ofs << "This is my output...\n";
  }
}
