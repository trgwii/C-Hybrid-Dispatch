#include "giraffe.h"
#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Giraffe {
  char *sound;
} Giraffe;

void Giraffe_vocalize(Animal *animal) {
  Giraffe *giraffe = (Giraffe *)animal->dynamic.data;
  printf("%s\n", giraffe->sound);
}

static Animal_VTable Giraffe_vtable = {
    .vocalize = &Giraffe_vocalize,
};

Animal Giraffe_create(void) {
  Giraffe *giraffe = (Giraffe *)malloc(sizeof(Giraffe));
  giraffe->sound = "Snort Snort HISS!";
  return (Animal){
      .id = AnimalID_Dynamic,
      .dynamic = {.data = giraffe, .vtable = &Giraffe_vtable},
  };
}

void Giraffe_destroy(Animal *animal) { free(animal->dynamic.data); }
