#include "LFSR.hpp"

int main(int argc, char* argv[]) {
  if(argc != 5) {
    cout << "./PhotoMagic [input file] [output file] [seed] [tap]" << endl;
    return 1;
  }
  
  string input_filename(argv[1]);
  string output_filename(argv[2]);
  string seed(argv[3]);
  int tap = atoi(argv[4]);
  
  LFSR randomizer(seed, tap);

  Image input_image;
  if (!input_image.loadFromFile(input_filename)) {
    cout << "1" << endl;
    return -1;
  }
  
  Image output_image;
  if (!output_image.loadFromFile(input_filename)) {
    cout << "2" << endl;
    return -1;
  }
  // p is a pixel
  Color p;
  
  // create photographic negative image of upper-left 200 px square
  for (int x = 0; x < 1465; x++) {
    for (int y = 0; y < 1240; y++) {
      p = input_image.getPixel(x, y);
      p.r = p.r ^ randomizer.generate(tap);
      p.g = p.g ^ randomizer.generate(tap);
      p.b = p.b ^ randomizer.generate(tap);
      input_image.setPixel(x, y, p);
    }
  }
  
  Vector2u size = input_image.getSize();
  RenderWindow window1(VideoMode(size.x, size.y), "output");
  RenderWindow window2(VideoMode(size.x, size.y), "input");
  
  Texture texture;
  texture.loadFromImage(input_image);
  
  Texture texture_output;
  texture_output.loadFromImage(output_image);
  
  Sprite sprite_input;
  sprite_input.setTexture(texture);
  // sprite_input.scale(.25f, .25f);
  
  Sprite sprite_output;
  sprite_output.setTexture(texture_output);
  // sprite_output.scale(.25f, .25f);
  
  while (window1.isOpen() && window2.isOpen()) {
    Event event;
    while (window1.pollEvent(event)) {
      if (event.type == Event::Closed)
        window1.close();
    }
    while (window2.pollEvent(event)) {
      if (event.type == Event::Closed)
        window2.close();
    }
    window1.clear();
    window1.draw(sprite_input);
    window1.display();

    window2.clear();
    window2.draw(sprite_output);
    window2.display();
  }
  
  if (!input_image.saveToFile("output.jpg"))
    return -1;
  
  return 0;
}
