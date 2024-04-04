#include "dog.h"
#include <stdio.h>

void __attribute__((noinline)) Dog_vocalize(Dog *dog) {
  printf("%s\n", dog->sound);
}
