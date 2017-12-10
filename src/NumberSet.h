#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <vector>
#include <bitset>
#include <iosfwd>

class NumberSet
{
 public:
  bool isEmpty() const;
  void add(int x);
  void remove(int x);
  bool test(int loc) const;
  friend std::ostream& operator<<(std::ostream& os, NumberSet const& ns);
  std::vector<int> getContents() const;

 private:
  std::bitset<9> m_set; // Least significant bit represents a '1' till most significant bit a '9'.
                        // A number is in the set when its bit is set.
};

#endif
