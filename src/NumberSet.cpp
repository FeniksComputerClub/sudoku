#include "sys.h"
#include "debug.h"
#include "NumberSet.h"
#include <iostream>

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

std::ostream& operator<<(std::ostream& os, NumberSet const& ns)
{
  if (DEBUG) {os << ns.m_set << ":";}
  if (ns.isEmpty()) { // If empty
    os << '*';        // Print empty char
  } else {
    for (auto val : /*vector*/ ns.getContents()) {  // For each number in NumberSet
      if (val != 0) {                               //  Ignore zeroes
        os << val;                                  //   Output that number
      }
    }
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
