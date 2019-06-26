#include "RingBuffer.hpp"
#include "GuitarString.hpp"

#define CONCERT_A 440.0
#define SAMPLES_PER_SEC 44100
const int keyboard_size = 37;

vector<Int16> makeSamplesFromString(GuitarString gs) {
  vector<Int16> samples;
  
  gs.pluck();
  int duration = 8;
  for (int i= 0; i < SAMPLES_PER_SEC * duration; i++) {
    gs.tic();
    samples.push_back(gs.sample());
  }

  return samples;
}

int main(int argc, char* argv[]) {
  RenderWindow window(VideoMode(300, 200), "SFML Guitar Hero Lite");
  
  double freq;
  vector<Int16> sample;
  
  vector<vector<Int16>> samples(keyboard_size);
  vector<SoundBuffer> buffers(keyboard_size);
  vector<Sound> sounds(keyboard_size);
  
  string keyboard = "q2we4r5ty7u8i9op-[=zxdcfvgbnjmk,.;/' ";
  
  for (int i = 0; i < (signed)keyboard.size(); i++) {
    freq = CONCERT_A * pow(2, ( (i - 24)/12.0));
    GuitarString tmp = GuitarString(freq);
    
    sample = makeSamplesFromString(tmp);
    samples[i] = sample;
    
    if (!buffers[i].loadFromSamples(&samples[i][0], samples[i].size(), 2, SAMPLES_PER_SEC)) {
      throw
	runtime_error("SoundBuffer: failed to load from samples.");
    }
    
    sounds[i].setBuffer(buffers[i]);
  }

  while (window.isOpen()) {
    Event event;
    while (window.pollEvent(event)) {
      if (event.type == Event::Closed)
        window.close();
      if (event.type == Event::TextEntered) {
          if (event.text.unicode < 128) {
            char key = static_cast<char>(event.text.unicode);
            for (int i = 0; i < (signed)keyboard.size(); i++) {
              if (keyboard[i] == key) {
                cout << "Keyboard key is: " << keyboard[i] << endl;
                cout << "Attempting to play sound..." << endl;
                sounds[i].play();
                break;
              }
            }
          }
        }
      }

    window.clear();
    window.display();
  }
  return 0;
}
