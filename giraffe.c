#include "giraffe.h"
#include "animal.h"
#include <stdio.h>

typedef struct Giraffe {
  char *sound;
} Giraffe;

void Giraffe_vocalize(Animal *animal) {
  printf("%s\n", ((Giraffe *)&animal->dynamic)->sound);
}

static Animal_VTable Giraffe_vtable = {
    .vocalize = &Giraffe_vocalize,
};

Animal Giraffe_create(void) {
  Animal animal = {
      .id = (size_t)&Giraffe_vtable,
      .dynamic = NULL,
  };
  Giraffe *giraffe = (Giraffe *)&animal.dynamic;
  giraffe->sound = "Snort Snort HISS!";
  return animal;
}

void Giraffe_destroy(Animal *animal) { (void)animal; }
