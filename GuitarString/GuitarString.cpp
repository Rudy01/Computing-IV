#include "GuitarString.hpp"

GuitarString::GuitarString(double frequency):buff(ceil(SAMPLING_RATE / frequency)) {
  N = ceil(SAMPLING_RATE / frequency);

  for (int i = 0; i < N; i++)
    buff.enqueue((int16_t)0);
  
  _tic = 0;
}

GuitarString::GuitarString(vector<Int16> init):buff(init.size()) {
  N = init.size();
  
  for (vector<Int16>::iterator i = init.begin(); i < init.end(); i++)
    buff.enqueue((int16_t) * i);

  _tic = 0;
}

void GuitarString::pluck() {
  for (int i = 0; i < N; i++)
    buff.dequeue();
  
  for (int i = 0; i < N; i++)
    buff.enqueue((Int16)(rand() & 0xffff));
}

void GuitarString::tic() {
  int16_t karplus = ((buff.dequeue() + buff.peek()) / 2)  * ENERGY_DECAY_FACTOR;
  
  buff.enqueue((Int16)karplus);

  _tic++;
}

Int16 GuitarString::sample() {
  return (Int16)buff.peek();
}

int GuitarString::time() {
  return _tic;
}
