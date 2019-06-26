#include "ED.hpp"

int main(int argc, char* argv[]) {
  sf::Clock clock;
  sf::Time t = clock.getElapsedTime();
  
  string string1, string2;
  cin >> string1 >> string2;
  
  ED ed_test(string1, string2);
  
  int distance = ed_test.OptDistance();
  string alignment = ed_test.Alignment();
  
  cout << alignment << endl << "Edit distance = " << distance << endl << "Execution time is " << t.asSeconds() << " seconds" << endl;
  cout << string1.length() << endl << string2.length() << endl;

  return 0;
}
