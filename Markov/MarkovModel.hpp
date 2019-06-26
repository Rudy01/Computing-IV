#ifndef MarkovModel_hpp
#define MarkovModel_hpp

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;

class MarkovModel {
public:
  MarkovModel(string, int);
  int order();
  int freq(string);
  int freq(string, char);
  char randk(string);
  string gen(string, int);
  friend std::ostream& operator<< (ostream&, MarkovModel&);
  
private:
  int _order;
  map <string, int> _kgrams;
  string _alphabet;
  string init;
};
#endif
