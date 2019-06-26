#include "LFSR.hpp"

LFSR::LFSR(string seed, int t) {
  bits = seed;
  ctap = t;
}

int LFSR::step() {
  int tap = bits.length() - ctap - 1;
  int result = bits[0] ^ bits[tap];
  ostringstream ostring;
  
  for(string::size_type i = 0; (unsigned)i < bits.length() - 1; i++)
    ostring << bits[i + 1];
  
  ostring << result;
  bits = ostring.str();
  return result;
}

int LFSR::generate(int k) {
  int x = 0;
  for(int i = 0; i < k; i++)
    x = (x * 2) + step();
  return x;
}

ostream& operator<< (ostream &out, LFSR &c) {
  out << c.bits;
  return out;
}
