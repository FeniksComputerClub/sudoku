#include "sys.h"
#include "debug.h"
#include "Field.h"
#include <iostream>

//ReturnType Class::Function(paramType paramName) { ... };

Field::Field() : m_storage(m_fieldSize, NumberSet()) //Set private:storage to a new Vector of (x many, y's)
{  //Constructor
  DoutEntering(dc::notice, "Field()");
}


/*TODO*/ // Comments... @sjaak3136, do something about them.
Field::Field(std::string const& contents) : m_storage(m_fieldSize, NumberSet()) // For inputing a sudoku
{
  DoutEntering(dc::notice, "Field(\"" << contents << "\") [this = " << (void*)this << "]");
  ASSERT(contents.length() == m_fieldSize);
  std::string allowedDigits = "123456789"; /*TODO*/ // Move this
  /*for (auto c:s) {    // Split input s into individual 1-long-strings
    if (allowedDigits.find(c) != std::string::npos) {            // Check if ^that^ is allowed to go into the sudoku (i.e. a number, not a spacer)
      m_storage[*LOCATION*].add(std::stoi(c);
    }*/
  for (unsigned int loc = 0; loc < m_fieldSize; ++loc) {
    if (allowedDigits.find(contents[loc]) != std::string::npos) { // Check if the char at location loc of input-data contents is allowed to go into the sudoku (i.e. a number, not a spacer)
      //Dout(dc::notice, "loc:" << loc << "; contents[loc]:" << contents[loc] << "; type:" << typeid(contents[loc]).name());
      //Dout(dc::notice, "atoi(&(contents[loc])):" << std::atoi(&(contents[loc])));
      char c = contents[loc];  // This is needed because else atoi() will continue reading the string untill it hits a whitespace...
                        // Which will result in digits that are bigger than 9 sometimes, and thus don't do well with the NumberSet.add...
                        // Even tho atoi (to my understanding) converts a char to int, and a char can't be longer than one...
                        // But it can continue reading from that pointer... Ah, I think I see why it does this now... 
                        // But that still would be weird, because if you want to convert multiple digits to ints you would use stoi I'd assume...
                        /*TODO*/ // Try doing this by substringing, maybe then it'll work, but for now I'll just use this, because I'm gonna take a break

      /*TODO*/ /*Why???*/ Dout(dc::notice, "c:" << c);    // Forget what I just said... it still crashes for some reason if this is commented out...
      m_storage[loc].add(std::atoi(&c));  // Convert input char into int, and put that into the correspoding NumberSet located at location loc
    }
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
    m_storage[i].add(r);
  }
}

std::vector<NumberSet*> Field::getRow(Direction dir) { //TODO add X, Y
  DoutEntering(dc::notice, "Field::getRow(" << dir << ") [this = " << (void*)this << "]");
  std::vector<NumberSet*> row(m_fieldWidth); //May throw unexpected behavior/crash due to dead pointers 
  int dir_offset = (dir == horizontal) ? 1 : 9;
  for (int i = 0; i < m_fieldWidth; ++i) {
    row[i] = &m_storage[i * dir_offset];
  }
  return row;
}

NumberSet Field::get2D(int x, int y) const
{
  return m_storage[y * m_fieldWidth + x];
}
