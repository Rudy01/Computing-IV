#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main

#include <boost/test/unit_test.hpp>
#include "GuitarString.hpp"

BOOST_AUTO_TEST_CASE(GS) {
  vector<Int16> v;
  
  v.push_back(0);
  v.push_back(2000);
  v.push_back(4000);
  v.push_back(-10000);

  BOOST_REQUIRE_NO_THROW(GuitarString gs = GuitarString(v));

  GuitarString gs = GuitarString(v);
  
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 0);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 2000);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 4000);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == -10000);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 996);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 2988);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == -2988);
  
  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == -4483);

  gs.tic();
  cout << "Sample is: " << gs.sample() << endl;
  BOOST_REQUIRE(gs.sample() == 1984);
  gs.tic();

  cout << "Sample is: " << gs.sample();
  BOOST_REQUIRE(gs.sample() == 0);
}
