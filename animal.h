#pragma once

#include <stddef.h>

#include "cat.h"
#include "dog.h"

#define STATICALLY_KNOWN_ANIMALS                                               \
  X(Cat, Cat, 0)                                                               \
  X(Dog, Dog, 1)

typedef enum AnimalID {
#define X(name, type, count) AnimalID_##name = (count << 1) | 1,
  STATICALLY_KNOWN_ANIMALS
#undef X
} AnimalID;

struct Animal;
typedef struct Animal Animal;

typedef struct Animal_VTable {
  void (*vocalize)(Animal *animal);
} Animal_VTable;

struct Animal {
  union {
#define X(name, type, count) type name;
    STATICALLY_KNOWN_ANIMALS
#undef X
    void *dynamic;
  };
  size_t id;
};

void Animal_vocalize(Animal *animal);
