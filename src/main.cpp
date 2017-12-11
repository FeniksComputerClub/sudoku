#include "sys.h"
#include "debug.h"
#include "Field.h"
#include <iostream>

int main()
{
#ifdef DEBUGGLOBAL
  GlobalObjectManager::main_entered();
#endif
  Debug(NAMESPACE_DEBUG::init());

  std::cout << "Starting" << std::endl;
  Field f0 = Field();  //Initiate Field
  f0.fillRand(42);     //Fill field with random ints (seed:42)
  f0.print();
}
