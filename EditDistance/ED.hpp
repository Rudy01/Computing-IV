#ifndef ED_HPP
#define ED_HPP

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <SFML/System.hpp>

using namespace std;

class ED {
public:
  ED(string, string);
  int penalty(char, char);
  int min(int, int, int);
  int OptDistance();
  string Alignment();
  
private:
  string s1, s2;
  vector<vector<int>> matrix;
};

#endif
