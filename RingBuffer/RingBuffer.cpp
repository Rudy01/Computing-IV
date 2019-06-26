// Copyright 2019 Rutvik Tarikere

#include "RingBuffer.hpp"

RingBuffer::RingBuffer(int capacity) {
  if (capacity < 1) {
    throw
      invalid_argument("RB constructor: capacity must be greater than zero");
  }
  last = 0;
  first = 0;
  _size = 0;
  _capacity = capacity;
  buffer.resize(capacity);
}

int RingBuffer::size() {
  cout << "Size: ";
  return _size;
}

bool RingBuffer::isEmpty() {
  if (_size == 0)
    return true;
  else
    return false;
}

bool RingBuffer::isFull() {
  if (_size == _capacity)
    return true;
  else
    return false;
}

void RingBuffer::enqueue(int16_t x) {
  if (isFull()) {
    throw
      runtime_error("enqueue: can't enqueue to a full ring");
  }
  if (last >= _capacity)
    last = 0;
  buffer.at(last) = x;
  last++;
  _size++;
}

int16_t RingBuffer::dequeue() {
  if (isEmpty()) {
    throw
      runtime_error("dequeue: can't dequeue to an empty ring");
  }
  int16_t _first = buffer.at(first);
  buffer.at(first) = 0;

  first++;
  _size--;

  if (first >= _capacity)
    first = 0;

  return _first;
}

int16_t RingBuffer::peek() {
  if (isEmpty()) {
    throw
      runtime_error("peek: can't peek an empty ring");
  }

  cout << "Peek: ";
  return buffer.at(first);
}
