#include "sierpinski.hpp"

int main(int argc, char* argv[]) {
  if (argc < 3 || argc > 4) {
    cout << "./sierpinski [depth] [side length]" << endl;
    return -1;
  }
  
  int depth = atoi(argv[1]);
  int side = atoi(argv[2]);
  
  if (depth < 0) {
    cout << "depth should be greater than 0" << endl;
    return -1;
  }
  
  Sierpinski obj(depth, side);
  
  int window_height = 0.5 * sqrt(3.0) * side;
  
  RenderWindow window(VideoMode(side, window_height), "Sierpinkski");
  
  window.setFramerateLimit(1);
  
  while (window.isOpen()) {
    Event event;
    
    while (window.pollEvent(event))
      if (event.type == Event::Closed)
        window.close();
    
    window.clear();
    window.draw(obj);
    window.display();
  }
  
  return 0;
}
