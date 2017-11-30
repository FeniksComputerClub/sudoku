#include "Field.h"
#include <iostream>
#include "Debug.h"
#if 0
class Field {
 public:
  Field() {
    std::cout << "Field Constructing" << std::cout;
  }

  ~Field() {
    std::cout << "Field Destructing" << std::cout;
  }
#endif

//ReturnType Class::Function(paramType paramName) { ... };

Field::Field() : m_storage(m_fieldSize, NumberSet()) //Set private:storage to a new Vector of (x many, y's)
{  //Constructor
  if (DEBUG) {std::cout << "Field Constructing" << std::endl;}
  if (DEBUG) {std::cout << "-Field Constructed" << std::endl;}
}

Field::Field(std::string s) : m_storage(m_fieldSize, NumberSet()) //FOR DEBUG PURPOSES ONLY
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
  //DEBUG   std::cout << "Field Destructing" << std::endl;
}

//TODO get(x,y) from storage

void Field::print() const
{
  int i=0;
  if (DEBUG) {std::cout << "print" << std::endl;}
  //for (int i=0; i<m_fieldSize; ++i) {
  for (int y=0; y<m_fieldHeight; ++y) {
    for (int x=0; x<m_fieldWidth; ++x) {
      i=(y*m_fieldWidth)+x;
      m_storage[i].print();
      std::cout << " ";
      if ((i+1)%9==0) { std::cout << std::endl; } //Field Edge (Right) Return
      //DEBUG std::cout << "i:" << i << " %3:" << i%3 << " %9:" << i%9 << " ";
      //DEBUG std::cout << "%9:" << i%9 << " ";
      if ( ((i+1)%3==0) && not((i)%9==8) ) { std::cout << "| "; } //Vertical Seperators
      //TODO REMOVE if ((i% (m_fieldSize/3) ==((m_fieldSize/3)-1) ) && !(i==0 || i==m_fieldSize+1)) { std::cout << "─ ─ ─ ┼ ─ ─ ─ ┼ ─ ─ ─\n"; } //Horizontal Seperators (if current_proccessed_nummer (i) is devidable by (totalSize / 3) (and you are not at the top of the Field) then print seperator)
    }
  }
  //DEBUG   std::cout << m_storage[5] << std::endl;
  if (DEBUG) {std::cout << "-print" << std::endl;}
}

void Field::fillRand(int seed)
{
  if (DEBUG) {std::cout << "fillRand" << std::endl;}
  std::srand(seed);
  for (int i=0; i<m_fieldSize; ++i) {
    int r = (std::rand()%9)+1; //+1 because else you are making zeroes possible in a sudoku (which they (usualy) aren't)
    if (DEBUG) {std::cout << "r:" << r << std::endl;}
    m_storage[i].add(r);
    //DEBUG std::cout << r << " " << m_storage[i].print() << std::endl;
  }
  if (DEBUG) {std::cout << "-fillRand" << std::endl;}
  //void print();//TODO
}

#if 0
std::vector<int> Field::BitsetToInts(std::bitset<10> bs) const //TODO MOVE THIS TO CLASS THAT IS A WRAPPER AROUND BITSET
{
  std::vector<int> out(9, 0);
  // std::cout << '=' <<  out.size() << std::endl;
  for (unsigned int i=0; i<bs.size(); ++i) {
    if (bs.test(i)) {
      //DEBUG   std::cout << bs.test(i) << i << ' ';
      out[i] = i;
    }
  }
  // std::cout << std::endl;
  return out; //return a vector of all values that are in the bitset
}
#endif
//TODO add 2D function (or 2DField Class)
//2D() returns vector(9*9) of m_storage
