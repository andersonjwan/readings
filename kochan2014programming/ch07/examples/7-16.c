#include <stdio.h>

/* forward declaration(s) */
void auto_static(void);

int main(void) {
  int i;

  for(i = 0; i < 5; ++i) {
    auto_static();
  }

  return 0;
}

void auto_static(void) {
  auto int autoVar = 1;     // initialization -> occurs each function call.
  static int staticVar = 1; // initialization -> occurs only once!

  printf("automatic = %d, static = %d\n", autoVar, staticVar);

  ++autoVar;
  ++staticVar;
}
