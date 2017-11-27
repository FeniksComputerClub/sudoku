#include "NumberSet.h"

NumberSet::NumberSet() {}

NumberSet::~NumberSet() {}

bool NumberSet::isEmpty() const
{
  /*std::bitset<9> empty;
  return (m_set == empty);*/
  if (m_set.count == 0) {
    return true;
  }
  return false;
}

void NumberSet::add(int x) 
{
  std::cout << "NS: adding" << std::endl;
  std::cout << "b:" << m_set << "\nx:" << x << std::endl;
  m_set[x] = true;  //TODO WHY U TROW SEGMENTATION FAULT
  std::cout << "-NS: added" << std::endl;
}

void NumberSet::remove(int x)
{
  m_set[x] = false;
}

bool NumberSet::test(int loc) const
{
  return m_set[loc];
}

void NumberSet::print() const
{
  //DEBUG   std::cout << "NumberSet print called!" << std::endl << m_set << std::endl;
  if (!isEmpty()) { //if not empty
    for (unsigned int i = 0; i < m_set.size(); ++i) {
      if (m_set[i]) { //get "active" content (1's)
        std::cout << i /*<< std::endl*/; //print
      }
    }
  } else { //if empty
    std::cout << '*'; //print empty char
  } 
}

//std::bitset<9> m_storage;
