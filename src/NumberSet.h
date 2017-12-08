#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <vector>
#include <bitset>
#include <iostream>

class NumberSet
{
 public:
  bool isEmpty() const;
  void add(int x);
  void remove(int x);
  bool test(int loc) const;
  void print() const;
  void printRaw() const;
  std::vector<int> getContents() const;

 private:
  std::bitset<9> m_set; // Least significant bit represents a '1' till most significant bit a '9'.
                        // A number is in the set when its bit is set.
};

#endif
