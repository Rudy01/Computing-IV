#include "LFSR.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(fiveBitsTapAtTwo) {
  LFSR l("00111", 2);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 0);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 1);
  BOOST_REQUIRE(l.step() == 0);
  
  LFSR l2("00111", 2);
  BOOST_REQUIRE(l2.generate(8) == 198);
}

BOOST_AUTO_TEST_CASE(elevenBitsTapAtEight) {
  LFSR lfsr("01101000010", 8);
  BOOST_REQUIRE(lfsr.step() == 1);
  BOOST_REQUIRE(lfsr.step() == 1);
  BOOST_REQUIRE(lfsr.step() == 0);
  BOOST_REQUIRE(lfsr.step() == 0);
  BOOST_REQUIRE(lfsr.step() == 1);
  BOOST_REQUIRE(lfsr.step() == 0);
  BOOST_REQUIRE(lfsr.step() == 0);
  BOOST_REQUIRE(lfsr.step() == 1);
  BOOST_REQUIRE(lfsr.step() == 0);
  BOOST_REQUIRE(lfsr.step() == 0);
  
  LFSR lfsr1("01101000010", 8);
  BOOST_REQUIRE(lfsr1.generate(5) == 25);
  BOOST_REQUIRE(lfsr1.generate(5) == 4);
  BOOST_REQUIRE(lfsr1.generate(5) == 30);
  BOOST_REQUIRE(lfsr1.generate(5) == 27);
  BOOST_REQUIRE(lfsr1.generate(5) == 18);
  BOOST_REQUIRE(lfsr1.generate(5) == 26);
  BOOST_REQUIRE(lfsr1.generate(5) == 28);
  BOOST_REQUIRE(lfsr1.generate(5) == 24);
  BOOST_REQUIRE(lfsr1.generate(5) == 23);
  BOOST_REQUIRE(lfsr1.generate(5) == 29);
}

BOOST_AUTO_TEST_CASE(fourBitsTapAtTwo) {
  LFSR l5("1001", 2);
  BOOST_REQUIRE(l5.step() == 1);
  BOOST_REQUIRE(l5.step() == 0);
  BOOST_REQUIRE(l5.step() == 1);
  
  LFSR l6("1001", 2);
  BOOST_REQUIRE(l6.generate(2) == 2);
}
