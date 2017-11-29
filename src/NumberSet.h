#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <vector>
#include <bitset>
#include <iostream>

class NumberSet
{
 public:
  NumberSet();
  ~NumberSet();
  bool isEmpty() const;
  void add(int x);
  void remove(int x);
  bool test(int loc) const;
  void print() const;
  void printRaw() const;
 private:
  std::bitset<9> m_set;
};

#endif
