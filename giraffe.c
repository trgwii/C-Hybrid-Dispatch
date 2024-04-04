#include "giraffe.h"
#include "animal.h"
#include <stdio.h>

typedef struct Giraffe {
  char *sound;
} Giraffe;

void Giraffe_vocalize(Animal *animal) {
  Giraffe *giraffe = (Giraffe *)&animal->dynamic.data;
  printf("%s\n", giraffe->sound);
}

static Animal_VTable Giraffe_vtable = {
    .vocalize = &Giraffe_vocalize,
};

Animal Giraffe_create(void) {
  Animal animal = {
      .id = AnimalID_Dynamic,
      .dynamic = {.data = NULL, .vtable = &Giraffe_vtable},
  };
  Giraffe *giraffe = (Giraffe *)&animal.dynamic.data;
  giraffe->sound = "Snort Snort HISS!";
  return animal;
}

void Giraffe_destroy(Animal *animal) { (void)animal; }
