#include <dlfcn.h>
#include <stdio.h>

#include "animal.h"

int main(void) {

  void *libgiraffe = dlopen("./libgiraffe.so", RTLD_NOW);
  Animal (*Giraffe_create)(void) = dlsym(libgiraffe, "Giraffe_create");
  void (*Giraffe_destroy)(Animal *) = dlsym(libgiraffe, "Giraffe_destroy");

  Animal giraffe = Giraffe_create();

  Animal animals[3] = {
      {.id = AnimalID_Dog, .Dog = {.sound = "Woof."}},
      {.id = AnimalID_Cat, .Cat = {.sound = "Meow."}},
      giraffe,
  };

  for (int i = 0; i < 3; i++) {
    Animal *animal = &animals[i];
    Animal_vocalize(animal);
  }
  Giraffe_destroy(&giraffe);
}
