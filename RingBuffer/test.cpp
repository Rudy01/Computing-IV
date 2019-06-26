// Copyright 2019 Rutvik Tarikere

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include "RingBuffer.hpp"

BOOST_AUTO_TEST_CASE(RBcontructor) {
  // normal constructor
  BOOST_REQUIRE_NO_THROW(RingBuffer(100));
  // this should fail
  BOOST_REQUIRE_THROW(RingBuffer(0), exception);
  BOOST_REQUIRE_THROW(RingBuffer(0), invalid_argument);
}

BOOST_AUTO_TEST_CASE(RBenque_dequeue) {
  RingBuffer rb(100);
  rb.enqueue(2);
  rb.enqueue(1);
  rb.enqueue(0);
  BOOST_REQUIRE(rb.dequeue() == 2);
  BOOST_REQUIRE(rb.dequeue() == 1);
  BOOST_REQUIRE(rb.dequeue() == 0);
  BOOST_REQUIRE_THROW(rb.dequeue(), runtime_error);
}

BOOST_AUTO_TEST_CASE(testcase3) {
  RingBuffer testcase3(100);
  testcase3.enqueue(50);
  testcase3.enqueue(20);
  BOOST_REQUIRE(testcase3.dequeue() == 50);
  BOOST_REQUIRE(testcase3.dequeue() == 20);
  BOOST_REQUIRE_THROW(testcase3.dequeue(), runtime_error);
}
