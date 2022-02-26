#include <stdio.h>

int main(void) {
  float f = 1.00;
  short int i = 100;
  long int l = 500L;
  double d = 15.00;

  printf("f + i = %f\n", f + i);                 /* i: int -> float;
                                                    result: float */
  printf("l / d = %lf\n", l / d);                /* l: long -> double;
                                                    result: double */
  printf("i / l + f = %f\n", i / l + f);         /* i: int -> long;
                                                    result: float */
  printf("l * i = %li\n", l * i);                /* i: int -> long;
                                                    result: long */
  printf("f / 2 = %f\n", f / 2);                 /* 2: int -> float;
                                                    result: float */
  printf("i / (d + f) = %lf\n", i / (d + f));    /* f: float -> double;
                                                    i: int -> double;
                                                    result: double */
  printf("l / (i * 2.0) = %f\n", l / (i * 2.0)); /* i: int -> float;
                                                    l: long -> float;
                                                    result: float */
  printf("l + i / (double) l = %lf\n",
         l + i / (double) l);                    /* l: long -> double;
                                                    i: int -> double;
                                                    l: long -> double;
                                                    result: double */
  return 0;
}
