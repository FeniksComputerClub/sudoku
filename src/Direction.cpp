#include "Direction.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, Direction const& dir) {
  if (dir.i == horizontal.i) {
    os << "Horizontal";
  }
  if (dir.i == vertical.i) {
    os << "Vertical";
  }
  return os;
}
