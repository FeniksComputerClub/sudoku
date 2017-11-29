#include "NumberSet.h"
#include "Debug.h"

NumberSet::NumberSet() {}

NumberSet::~NumberSet() {}

bool NumberSet::isEmpty() const
{
  /*std::bitset<9> empty;
  return (m_set == empty);*/
  if (m_set.count() == 0) {
    return true;
  }
  return false;
}

void NumberSet::add(int x) 
{
  if (DEBUG) {std::cout << "NS: adding" << std::endl;}
  m_set[x-1] = true;
  if (DEBUG) {std::cout << "b:" << m_set << "\nx:" << x << std::endl;}
  if (DEBUG) {std::cout << "-NS: added" << std::endl;}
}

void NumberSet::remove(int x)
{
  m_set[x-1] = false;
}

bool NumberSet::test(int loc) const
{
  return m_set[loc]; //TODO This might throw future bug, depending on implementation (somthing to do with things being off by 1)
}

void NumberSet::print() const
{
  //DEBUG   std::cout << "NumberSet print called!" << std::endl << m_set << std::endl;
  if (!isEmpty()) { //if not empty
    for (unsigned int i = 0; i < m_set.size(); ++i) {
      if (m_set[i]) { //get "active" content (1's)
        std::cout << i+1 /*<< std::endl*/; //print
      }
    }
  } else { //if empty
    std::cout << '*'; //print empty char
  } 
}

void NumberSet::printRaw() const
{
  std::cout << "i:";
  print();
  std::cout << " b:" << m_set << std::endl;
}

//TODO int get()
//if count>1:
//  throw MultiIntError
//else:
//  return int

//std::bitset<9> m_storage;
