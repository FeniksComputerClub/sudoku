#include "sys.h"
#include "debug.h"
#include "Field.h"
#include <iostream>

//ReturnType Class::Function(paramType paramName) { ... };

Field::Field() : m_storage(m_fieldSize, NumberSet()) //Set private:storage to a new Vector of (x many, y's)
{  //Constructor
  DoutEntering(dc::notice, "Field()");
}

Field::Field(std::string const& s) : m_storage(m_fieldSize, NumberSet()) /*TODO*/ // FOR DEBUG PURPOSES ONLY
{
  DoutEntering(dc::notice, "Field(\"" << s << "\") [this = " << (void*)this << "]");
  int foo=0; //PLACEHOLDER
  for (int i=0; i<m_fieldSize; ++i) {  //TODO MAKE A FIELD WITH THE NUMBERS IN STRING FOR TESTING PURPOSES
    foo += 1;
  }
}

Field::~Field()
{ //Destructor
  DoutEntering(dc::notice, "~Field() [this = " << (void*)this << "]");
}

void Field::print() const
{
  DoutEntering(dc::notice, "Field::print() [this = " << (void*)this << "]");
  for (int y = 0; y < m_fieldHeight; ++y) {
    for (int x = 0; x < m_fieldWidth; ++x) {
      std::cout << get2D(x,y) << " ";
      if ( (x + 1) % 3 == 0 && x + 1 != m_fieldWidth ) { std::cout << "| "; }   // Vertical Seperators (print after 3 NumberSets (except for the last column))
    }
    std::cout << std::endl;
    if ( (y + 1) % 3 == 0 && y + 1 != m_fieldHeight ) { std::cout << "─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─\n"; }   // Horizontal Seperator
  }
}

void Field::fillRand(int seed)
{
  DoutEntering(dc::notice, "Field::fillRand(" << seed << ") [this = " << (void*)this << "]");
  std::srand(seed);
  for (int i = 0; i < m_fieldSize; ++i) {
    int r = (std::rand() % 9) + 1; //+1 because else you are making zeroes possible in a sudoku (which they (usualy) aren't)
    Dout(dc::notice, "r:" << r);
    m_storage[i].add(r);
    Dout(dc::notice, r << " " << m_storage[i]);
  }
}

NumberSet Field::get2D(int x, int y) const
{
  return m_storage[y * m_fieldWidth + x];
}
