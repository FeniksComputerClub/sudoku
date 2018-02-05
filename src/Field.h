#ifndef FIELD_H
#define FIELD_H

#include "NumberSet.h"
#include <vector>
#include <bitset>

class Field
{
 public:
  // Construct an empty field.
  Field();

  /*!
   * @brief Construct a field from the string contents.
   *
   * String contents must exist of 81 chars. Every character that isn't a digit between
   * 1 and 9 is interpreted as empty space, otherwise put into the corresponding
   * position on the Field.
   *
   * @param contents String of contents.
   */
  Field(std::string const& contents);  //TODO

  //! Destructor.
  ~Field();

  void print() const;
  void fillRand(int seed);

  // Accessors.
  bool isLegal() const; //TODO test to see if the current state of the Field is allowed or is unacceptable
  NumberSet get2D(int x, int y) const; // Used to interface with the (1D vector) m_storage as if it were 2D /*TODO*/ maybe return pointers so it can be used to interface 2 way

 private:
  static int constexpr m_fieldWidth = 9;
  static int constexpr m_fieldHeight = 9;
  static int constexpr m_fieldSize = m_fieldWidth*m_fieldHeight;
  std::vector<NumberSet> m_storage; //123456789
};

#endif // FIELD_H

