#include "animal.h"

#ifdef DISPLAY_ASM
#define ATTR __attribute__((noinline))
#else
#define ATTR
#endif

void ATTR Animal_vocalize(Animal *animal) {
  switch (animal->id) {
#define X(name, type, count)                                                   \
  case AnimalID_##name:                                                        \
    name##_vocalize(&animal->name);                                            \
    break;
    STATICALLY_KNOWN_ANIMALS
#undef X
  default:
    ((Animal_VTable *)animal->id)->vocalize(animal);
    break;
  }
}
