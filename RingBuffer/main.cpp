// Copyright 2019 Rutvik Tarikere

#include "RingBuffer.hpp"

int main(int argc, char *argv[]) {
  /*
    ingBuffer(int capacity)  // create an empty ring buffer, with given max capacity
    int size()                // return number of items currently in the buffer
    bool isEmpty()            // is the buffer empty (size equals zero)?
    bool isFull()             // is the buffer full  (size equals capacity)?
    void enqueue(int16_t x)   // add item x to the end
    int16_t dequeue()         // delete and return item from the front
    int16_t peek()            // return (but do not delete) item from the front
  */

  RingBuffer test1(5);
  test1.enqueue(11);
  test1.enqueue(18);
  if (test1.isFull() == true)
    cout << "Ring Buffer is full" << endl;
  else
    cout << "Ring Buffer is not full" << endl;

  test1.enqueue(1998);

  cout << test1.size() << endl;

  test1.dequeue();

  if (test1.isEmpty() == true)
    cout << "Ring Buffer is empty" << endl;
  else
    cout << "Ring Buffer is not empty" << endl;

  test1.dequeue();

  cout << test1.peek() << endl;
  test1.dequeue();

  if (test1.isEmpty() == true)
    cout << "Ring Buffer is empty" << endl;
  else
    cout << "Ring Buffer is not empty" << endl;
  return 0;
}
