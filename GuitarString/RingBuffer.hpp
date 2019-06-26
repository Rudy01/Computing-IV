#ifndef RINGBUFFER_HPP
#define RINGBUFFER_HPP

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#include <math.h>
#include <limits.h>

#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;
using namespace sf;

class RingBuffer {
public:
  explicit RingBuffer(int _capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();

private:
  vector<int16_t> buffer;
  int first;
  int last;
  int capacity;
  int _size;
};
#endif
