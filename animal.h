#pragma once
#include "cat.h"
#include "dog.h"

#define STATICALLY_KNOWN_ANIMALS                                               \
  X(Cat, Cat)                                                                  \
  X(Dog, Dog)

typedef enum AnimalID {
#define X(name, type) AnimalID_##name,
  STATICALLY_KNOWN_ANIMALS
#undef X
      AnimalID_Dynamic,
} AnimalID;

struct Animal;
typedef struct Animal Animal;

typedef struct Animal_VTable {
  void (*vocalize)(Animal *animal);
} Animal_VTable;

struct Animal {
  union {
#define X(name, type) type name;
    STATICALLY_KNOWN_ANIMALS
#undef X
    struct {
      void *data;
      Animal_VTable *vtable;
    } dynamic;
  };
  AnimalID id;
  int pad0_;
};

void Animal_vocalize(Animal *animal);
