#include "ED.hpp"

ED::ED(string _s1, string _s2) {
  s1 = _s1;
  s2 = _s2;
}

int ED::penalty(char a, char b) {
  if (a == b)
    return 0;
  else
    return 1;
}

int ED::min(int a, int b, int c) {
  if(a < b && a < c)
    return a;

  if(b < a && b < c)
    return b;

  if(c < a && c < b)
    return c;

  return a;
}

int ED::OptDistance() {
  int N = s1.length();
  int M = s2.length();
  
  for(int i = 0; i <= M; i++) {
    vector<int> temp;
    matrix.push_back(temp);
    for(int j = 0; j <= N; j++) {
      matrix.at(i).push_back(0);
    }
  }

  for(int i = 0; i <= M; i++) 
    matrix[i][N] = 2 * (M - i);

  for(int j = 0; j <= N; j++)
    matrix[M][j] = 2 * (N - j);
  
  for(int i = M - 1; i >= 0; i--) {
    for(int j = N - 1; j >= 0; j--) {
      int opt1 = matrix[i + 1][j + 1] + penalty(s1[j], s2[i]);
      int opt2 = matrix[i + 1][j] + 2;
      int opt3 = matrix[i][j + 1] + 2;
      
      matrix[i][j] = min(opt1, opt2, opt3);
    }
  }
  return matrix[0][0];
}

string ED::Alignment() {
  ostringstream return_string;
  int M = s2.length();
  int N = s1.length();
  int i = 0, j = 0;
  int pen, opt1, opt2, opt3;
  string ret_str;

  while(i < M || j < N) {
    try {
      pen =  penalty(s1[j], s2[i]);
      opt1 = matrix.at(i + 1).at(j + 1) + pen;
    }
    catch(const out_of_range& error) {
      opt1 = -1;
    }
    
    try {
      opt2 = matrix.at(i + 1).at(j) + 2;
    }
    catch(const out_of_range& error) {
      opt2 = -1;
    }
    
    try {
      opt3 = matrix.at(i).at(j + 1) + 2;
    }
    catch(const out_of_range& error) {
      opt3 = -1;
    }

    if(matrix[i][j] == opt1) {
      return_string << s1[j] << " " << s2[i] << " " << pen << endl;
      i++;
      j++;
    }
    
    if(matrix[i][j] == opt2) {
      return_string << "- " << s2[i] << " 2" << endl;
      i++;
    }
    
    if(matrix[i][j] == opt3) {
      return_string << s1[j] << " - " << "2" << endl;
      j++;
    }
  }
  
  ret_str = return_string.str();
  return ret_str;
}
