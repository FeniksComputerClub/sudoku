#include "NumberSet.h"
#include "Debug.h"

bool NumberSet::isEmpty() const
{
  /*std::bitset<9> empty;
  return (m_set == empty);*/
  if (m_set.count() == 0) {
    return true;
  }
  return false;
}

void NumberSet::add(int x) //TODO rename to setActive? activate? set?
{
  ASSERT(1 <= x && x <= 9);
  if (DEBUG) {std::cout << "NS: adding" << std::endl;}
  m_set[x-1] = true;
  if (DEBUG) {std::cout << "b:" << m_set << "\nx:" << x << std::endl;}
  if (DEBUG) {std::cout << "-NS: added" << std::endl;}
}

void NumberSet::remove(int x) //TODO rename to clear? deactivate? reset?
{
  ASSERT(1 <= x && x <= 9);
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
    /*for (unsigned int i = 0; i < m_set.size(); ++i) {
      if (m_set[i]) { //get "active" content (1's)
        std::cout << i+1; //print
      /
    }*/
    for (auto val : /*vector*/ getContents()) {
      if (val!=0) {
        std::cout << val; //TODO HIER WAS IK
        //print vector content, not vecotr itself
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

std::vector<int> NumberSet::getContents() const //TODO WIP
{
  std::vector<int> content(9, 0); // Make empty vector
  if (DEBUG) { std::cout << m_set << ":"; }
  for (unsigned int i = 0; i < m_set.size(); ++i) {
    if (m_set[i]) {   //get "active" content (1's)
      content[i] = i+1;
      //DEBUG std::cout << i+1;
    }
  }
  //DEBUG std::cout << std::endl;
  return content;
}

//TODO int get()
//if count>1:
//  throw MultiIntError
//else:
//  return int

//std::bitset<9> m_storage;
