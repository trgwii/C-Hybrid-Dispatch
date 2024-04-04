#include "animal.h"

void __attribute__((noinline)) Animal_vocalize(Animal *animal) {
  switch (animal->id) {
#define X(name, type)                                                          \
  case AnimalID_##name:                                                        \
    name##_vocalize(&animal->name);                                            \
    break;
    STATICALLY_KNOWN_ANIMALS
#undef X
  case AnimalID_Dynamic:
    animal->dynamic.vtable->vocalize(animal);
  }
}
