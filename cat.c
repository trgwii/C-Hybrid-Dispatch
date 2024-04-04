#include "cat.h"
#include <stdio.h>

void __attribute__((noinline)) Cat_vocalize(Cat *cat) {
  printf("%s\n", cat->sound);
}
