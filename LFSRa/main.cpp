#include "LFSR.hpp"

int main(int argc, char* argv[]) {
  LFSR lfsr("01101000010", 8);

  cout << "Test case 1." << endl;
  for(int i = 0; i < 10; i++) {
    int bit = lfsr.step();
    cout << lfsr << " " << bit << endl;
  }

  LFSR lfsr1("01101000010", 8);
  cout << endl << "Test case 2." << endl;
  for(int i = 0; i < 10; i++) {
    int x = lfsr1.generate(5);
    cout << lfsr1 << " " << x << endl;
  }
  
  return 0;
}
