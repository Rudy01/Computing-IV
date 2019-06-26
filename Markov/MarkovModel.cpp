#include "MarkovModel.hpp"

MarkovModel::MarkovModel(string text, int k) : _order(k), init(text) {
  srand(static_cast<unsigned int>(time(NULL)));
  for (int i = 0; i < static_cast<int>(text.size()); i++) {
    if (string::npos == _alphabet.find(text[i])) {
      _alphabet.push_back(text[i]);
    }
  }
  for (int i = 0; i < static_cast<int>(text.size()); i++) {
    string temp1;
    string temp2;
    for (int j = i; j < i + k; j++) {
      if (j >= static_cast<int>(text.size())) {
	temp1.push_back(text[j - text.size()]);
      } else {
	temp1.push_back(text[j]);
      }
    }
    if (_kgrams.end() == _kgrams.find(temp1))
      _kgrams[temp1] = 1;
    else
      _kgrams[temp1] += 1;
    for (int j = 0; j < static_cast<int>(_alphabet.size()); j++) {
      if (_kgrams.end() == _kgrams.find(temp1 + _alphabet[j])) {
	_kgrams[temp1 + _alphabet[j]] = 0;
      }
    }
    for (int j = i; j < i + k + 1; j++) {
      if (j >= static_cast<int>(text.size())) {
	temp2.push_back(text[j - text.size()]);
      } else {
	temp2.push_back(text[j]);
      }
    }
    _kgrams[temp2] += 1;
  }
}

int MarkovModel::order() {
    return _order;
}

int MarkovModel::freq(string kgram) {
  if (static_cast<int>(kgram.size()) != _order)
    throw runtime_error("kgram is not size k");

  if (_order == 0)
    return static_cast<int>(init.size());
  else
    return _kgrams[kgram];
}

int MarkovModel::freq(string kgram, char c) {
  if (static_cast<int>(kgram.size()) != _order)
    throw std::runtime_error("kgram is not size k");
  if (_order ==0) {
    int count = 0;
    for (int i = 0; i < static_cast<int>(init.size()); i++) {
      if (init[i] == c) {
	count++;
      }
    }
    return count;
  } else {
    return  _kgrams[kgram + c];
  }
  return 0;
}

char MarkovModel::randk(string kgram) {
  if (static_cast<int>(kgram.size()) != _order || _kgrams.end() == _kgrams.find(kgram))
    throw runtime_error("Error: randk kgram not valid");
  string temp;
  for (int i = 0; i < static_cast<int>(_alphabet.size()); i++) {
    for (int j = 0; j < _kgrams[kgram + _alphabet[i]]; j++) {
      temp.push_back(_alphabet[i]);
    }
  }
  return temp[rand() % temp.size()];
}

string MarkovModel::gen(string kgram, int T) {
    string temp = kgram;
    string rValue = kgram;
    char c;

    for (int i = 0; i < T - _order; i++) {
        c = randk(temp);
        rValue.push_back(c);
        temp.erase(temp.begin());
        temp.push_back(c);
    }

    return rValue;
}

ostream& operator<< (ostream &out, MarkovModel &mm) {
  out << endl << "Order: " << mm._order << endl;
  out << "Alphabet: "<< mm._alphabet << endl;

  out << "Kgrams map: " << endl;
  
  map<string, int>::iterator it;

  for (it = mm._kgrams.begin(); it != mm._kgrams.end(); it++)
    out << it->first << "\t" << it->second << endl;
  return out;
}
