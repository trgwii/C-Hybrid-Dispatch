#include "animal.h"

void __attribute__((noinline)) Animal_vocalize(Animal *animal) {
  switch (animal->id) {
#define X(name, type)                                                          \
  case AnimalID_##name:                                                        \
    name##_vocalize(&animal->name);                                            \
    return;
    STATICALLY_KNOWN_ANIMALS
#undef X
  default:
    animal->dynamic.vtable->vocalize(animal);
    return;
  }
}
