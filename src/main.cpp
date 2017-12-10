#include <iostream>
#include "Field.h"

int main() {
  std::cout << "Starting" << std::endl;
  Field f0 = Field();  //Initiate Field
  f0.fillRand(42);     //Fill field with random ints (seed:42)
  f0.print();
}
