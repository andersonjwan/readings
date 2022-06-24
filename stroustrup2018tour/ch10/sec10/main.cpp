#include <cassert>
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

void
print_dir(fs::path p) {
  try {
    if(is_directory(p)) {
      std::cout << p << ":\n";

      for(const fs::directory_entry& x : fs::recursive_directory_iterator(p)) {
	std::cout << " " << x.path() << "\n";
      }
    }
  } catch(const fs::filesystem_error& e) {
    std::cerr << e.what() << "\n";
  }
}

int
main() {
  fs::path p = "./main.cpp";
  assert(fs::exists(p));

  if(is_regular_file(p)) {
    std::cout << p << " is a file; its size is " << file_size(p) << " bytes\n";
  }

  print_dir(fs::path("../../"));
}
