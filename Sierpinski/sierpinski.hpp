#ifndef SIERPINSKI_HPP
#define SIERPINSKI_HPP


#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
using namespace sf;

class Sierpinski : public Drawable {
public:
  Sierpinski(int, int);
  Sierpinski(Vector2f, Vector2f, Vector2f, int);
  void virtual draw(RenderTarget&, RenderStates) const;

private:
  int cdepth;
  Vector2f t, l, r;
  Vector2f p1, p2, p3;
  Sierpinski *t1, *t2, *t3;
};

#endif
