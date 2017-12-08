#ifndef FIELD_H
#define FIELD_H

#include <vector>
#include <bitset>
#include "NumberSet.h"

class Field
{
 public:
  Field();  // Default constructor (Needed because else it's only implied to exist when creating a new instance of Field, which the compiler doesn't seem to like)
  Field(std::string s); //TODO
  ~Field();
  void print() const;
  void fillRand(int seed);
  bool isLegal(); //TODO test to see if the current state of the Field is allowed or is unacceptable
  //std::vector<int> BitsetToInts(std::bitset<10> bs) const;

 private:
  static int constexpr m_fieldWidth = 9;
  static int constexpr m_fieldHeight = 9;
  static int constexpr m_fieldSize = m_fieldWidth*m_fieldHeight;
  std::vector<NumberSet> m_storage; //123456789
};

#endif // FIELD_H

