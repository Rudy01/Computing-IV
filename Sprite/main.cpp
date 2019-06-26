#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

int main(int argc, char *argv[]) {
  RenderWindow window(VideoMode(600, 600), "Sprite Assignment");
 
  Texture image;
  if (!image.loadFromFile("doge.png")) {
    std::cout << "Image cannot be opened\n";
    return EXIT_FAILURE;
  }
 
  image.setSmooth(true);
 
  Sprite dog;
  dog.setTexture(image);
  dog.scale(.25f, .25f);
  dog.setOrigin(732, 620);
  dog.move(100, 150);
  
  while (window.isOpen()) {
    Event event;
    while(window.pollEvent(event)) {
      
      if (event.type == Event::Closed) {
        window.close();
      }
     
      if(event.type == Event::KeyPressed) {
	switch(event.key.code) {
	case (Keyboard::S):
	  {
	    Color c = dog.getColor();
	    dog.setColor(Color(c.r, c.g, c.b, 255));
	  }
	  break;
	  
	case (Keyboard::H):
	  {
	    Color d = dog.getColor();
	    dog.setColor(Color(d.r, d.g, d.b, 0));
	  }
	  break;

	case (Keyboard::Left):
	  dog.move(-15, 0);
	  break;

	case (Keyboard::Right):
	  dog.move(15, 0);
	  break;

	case (Keyboard::Up):
	  dog.move(0, -15);
	  break;

	case (Keyboard::Down):
	  dog.move(0, 15);
	  break;
	  
	case (Keyboard::Escape):
	  return 0;
	  break;

	  // Note: Asked you why it didn't rotate 45 degrees, couldn't fix it  
	case (Keyboard::Space):
	  dog.rotate(45);
	  break;
	}
      }
    }
  
    window.clear();
    window.draw(dog);
    window.display();
  }
 
  return 0;
}
