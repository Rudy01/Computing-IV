#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>

using namespace std;

class RingBuffer {
public:
  RingBuffer(int capacity);
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
  int _capacity;
  int _size;
};
