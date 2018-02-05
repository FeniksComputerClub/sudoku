#include "Direction.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Direction const& dir) {
  os << dir.i; //TODO hor or vert?
  return os;
}
