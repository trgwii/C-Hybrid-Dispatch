#include "dog.h"
#include <stdio.h>

#ifdef DISPLAY_ASM
#define ATTR __attribute__((noinline))
#else
#define ATTR
#endif

void ATTR Dog_vocalize(Dog *dog) { printf("%s\n", dog->sound); }
