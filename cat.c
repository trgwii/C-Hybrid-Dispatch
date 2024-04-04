#include "cat.h"
#include <stdio.h>

#ifdef DISPLAY_ASM
#define ATTR __attribute__((noinline))
#else
#define ATTR
#endif

void ATTR Cat_vocalize(Cat *cat) { printf("%s\n", cat->sound); }
