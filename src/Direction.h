#ifndef DIRECTION_H
#define DIRECTION_H

#include <iosfwd>

struct DirectionPOD {
  int i;
};

static constexpr DirectionPOD horizontal{0};
static constexpr DirectionPOD vertical{1};

class Direction : protected DirectionPOD {
  friend std::ostream& operator<<(std::ostream& os, Direction const& dir);
  public:
    bool operator==(DirectionPOD dirPOD) { return i == dirPOD.i; }
};

#endif  //DIRECTION_H
