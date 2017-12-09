#include "NumberSet.h"
#include "Debug.h"

bool NumberSet::isEmpty() const
{
  if (m_set.count() == 0) { // If this NumberSet contains no active bits/numbers
    return true;
  }
  return false;
}

void NumberSet::add(int x) //TODO rename to setActive? activate? set?
{
  ASSERT(1 <= x && x <= 9);
  if (DEBUG) {std::cout << "NS: adding" << std::endl;}
  m_set[x - 1] = true;
  if (DEBUG) {std::cout << "b:" << m_set << "\nx:" << x << std::endl;}
  if (DEBUG) {std::cout << "-NS: added" << std::endl;}
}

void NumberSet::remove(int x) //TODO rename to clear? deactivate? reset?
{
  ASSERT(1 <= x && x <= 9);
  m_set[x - 1] = false;
}

bool NumberSet::test(int loc) const
{
  ASSERT(0 <= loc && loc <= 8);
  return m_set[loc]; //TODO This might throw future bug, depending on implementation (somthing to do with things being off by 1)
}

void NumberSet::print() const
{
  if (DEBUG) {std::cout << "NumberSet print called!\n b:" << m_set << std::endl;}
  if (!isEmpty()) { // If not empty
    /*for (unsigned int i = 0; i < m_set.size(); ++i) {
      if (m_set[i]) { //get "active" content (1's)
        std::cout << i+1; //print
      /
    }*/
    for (auto val : /*vector*/ getContents()) { // For each number in NumberSet
      if (val != 0) {                           //  Ignore zeroes
        std::cout << val;                       //   Output that number
      }
    }
  } else { // If empty
    std::cout << '*'; // Print empty char
  } 
}

void NumberSet::printRaw() const
{
  std::cout << m_set << ":";
  print();
  std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& os, NumberSet const& ns)
{
  if (DEBUG) {
    ns.printRaw();
  } else {
    ns.print();
  }
  return os;
}

std::vector<int> NumberSet::getContents() const
{
  std::vector<int> content(9, 0); // Make empty vector
  if (DEBUG) {std::cout << m_set << ":";}
  for (unsigned int i = 0; i < m_set.size(); ++i) {
    if (m_set[i]) {   // Get "active" content (1's)
      content[i] = i + 1;
    }
  }
  return content; // Return a vector of all contents of the NumberSet (and zeroes because @sjaak doesn't want to have to resize vectors)
}
