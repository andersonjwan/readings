#include <iostream>
#include <string>

using std::cout;

enum class Color {
  RED,
  BLUE,
  GREEN
};

enum class TrafficLight {
  GREEN,
  YELLOW,
  RED
};

TrafficLight& operator++(TrafficLight& t) {
  switch(t) {
  case TrafficLight::GREEN: return t = TrafficLight::YELLOW;
  case TrafficLight::YELLOW: return t = TrafficLight::RED;
  case TrafficLight::RED: return t = TrafficLight::GREEN;
  }
}

std::string toString(const TrafficLight& t) {
  switch(t) {
  case TrafficLight::GREEN: return "GREEN";
  case TrafficLight::YELLOW: return "YELLOW";
  case TrafficLight::RED: return "RED";
  }
}



int
main(void) {
  Color c1 = Color::RED;
  TrafficLight l1 = TrafficLight::RED;

  for(int i = 0; i < 10; ++i) {
    // change the traffic signal 10 times
    cout << "Traffic signal changed from " << toString(l1) << " to "
	 << toString(++l1) << "\n";
  }
}
