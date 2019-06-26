#ifndef LFSR_HPP
#define LFSR_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

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
