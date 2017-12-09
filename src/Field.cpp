#include "Field.h"
#include <iostream>
#include "Debug.h"

//ReturnType Class::Function(paramType paramName) { ... };

Field::Field() : m_storage(m_fieldSize, NumberSet()) //Set private:storage to a new Vector of (x many, y's)
{  //Constructor
  if (DEBUG) {std::cout << "Field Constructing" << std::endl;}
  if (DEBUG) {std::cout << "-Field Constructed" << std::endl;}
}

Field::Field(std::string s) : m_storage(m_fieldSize, NumberSet()) /*TODO*/ // FOR DEBUG PURPOSES ONLY
{
  if (DEBUG) {std::cout << "Field Constructing from string" << std::endl;}
  int foo=0; //PLACEHOLDER
  for (int i=0; i<m_fieldSize; ++i) {  //TODO MAKE A FIELD WITH THE NUMBERS IN STRING FOR TESTING PURPOSES
    foo += 1;
  }
  if (DEBUG) {std::cout << "-Field constructed from string" << std::endl;}
}

Field::~Field()
{ //Destructor
  if (DEBUG) {std::cout << "Field Destructing" << std::endl;}
}

void Field::print() const
{
  int loc = 0;
  if (DEBUG) {std::cout << "print" << std::endl;}
  for (int y = 0; y < m_fieldHeight; ++y) {
    for (int x = 0; x < m_fieldWidth; ++x) {
      loc = y * m_fieldWidth + x;
      std::cout << m_storage[loc] << " ";
      if ( (loc + 1) % 9 == 0) { std::cout << std::endl; } // Field Edge (Right) Return
      if ( (loc + 1) % 3 == 0 && not(loc % 9 == 8) ) { std::cout << "| "; }   // Vertical Seperators
      if ( (y + 1) % 3 == 0 && x == m_fieldWidth - 1 && loc != m_fieldSize - 1 ) { std::cout << "─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─\n"; }   // Horizontal Seperators
    }
  }
  if (DEBUG) {std::cout << "-print" << std::endl;}
}

void Field::fillRand(int seed)
{
  if (DEBUG) {std::cout << "fillRand" << std::endl;}
  std::srand(seed);
  for (int i = 0; i < m_fieldSize; ++i) {
    int r = (std::rand() % 9) + 1; //+1 because else you are making zeroes possible in a sudoku (which they (usualy) aren't)
    if (DEBUG) {std::cout << "r:" << r << std::endl;}
    m_storage[i].add(r);
    if (DEBUG) {std::cout << r << " " << m_storage[i] << std::endl;}
  }
  if (DEBUG) {std::cout << "-fillRand" << std::endl;}
}

//TODO get(x,y) from storage
//TODO add 2D function (or 2DField Class)
//2D() returns vector(9*9) of m_storage
