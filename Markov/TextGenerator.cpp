#include "MarkovModel.hpp"

int main(int argc, const char* argv[]) {
  if (argc != 3) {
    cout << "Usage: ./TextGenerator int K int T" << endl;
    return 1;
  }
  
  int k = atoi(argv[1]);
  int T = atoi(argv[2]);
  string input;
  string current;
  while (cin >> current) {
    input += " " + current;
    current = "";
  }
  MarkovModel model(input, k);
  string temp;
  for (int i = 0; i < k; i++)
    temp.push_back(input[i]);
  cout << model.gen(temp, T) << endl;

  return 0;
}
