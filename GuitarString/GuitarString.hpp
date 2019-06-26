#ifndef GUITARSTRING_HPP
#define GUITARSTRING_HPP

#include "RingBuffer.hpp"

const int SAMPLING_RATE = 44100;
const double ENERGY_DECAY_FACTOR = 0.996;

class GuitarString {
public:
  GuitarString(double frequency);
  GuitarString(vector<Int16> init);
  
  void pluck();
  void tic();
  Int16 sample();
  int time();
  
private:
  RingBuffer buff;
  int N;
  int _tic;
};
#endif
