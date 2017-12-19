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
  //Field f0 = Field();  //Initiate Field
  //f0.fillRand(42);     //Fill field with random ints (seed:42)
  //f0.print();
  
  Field f1 = Field(
    "123456789" //"53  7    "
    "6  195   "
    " 98    6 "
    "8   6   3"
    "4  8 3  1"
    "7   2   6"
    " 6    28 "
    "   419  5"
    "    8  79"
  );
  f1.print();
}
