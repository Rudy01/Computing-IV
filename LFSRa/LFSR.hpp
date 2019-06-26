#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class LFSR {
public:
  LFSR(string, int);
  int step();
  int generate(int);
  friend ostream& operator<< (ostream&, LFSR&);

private:
  string bits;
  int ctap;
};

#endif
