#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <bitset>
#include "NumberSet.h"

class Field
{
 public:
  Field();
  Field(std::string s);
  ~Field();
  void print() const;
  void fillRand(int seed);
  //std::vector<int> BitsetToInts(std::bitset<10> bs) const;

 private:
  std::vector<NumberSet> m_storage; //123456789
  int const m_fieldSize = 81;
};

#endif // FIELD_H

