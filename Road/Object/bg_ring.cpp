
#include "bg_ring.h"
#include "../MyLib/graph.h"


BgRing::BgRing(const int& ring_num,
           const float& radius,
           const float& depth,
           const float& speed) :
radius(radius),
depth(depth),
speed(speed)
{
  for (int i = 0; i < ring_num; ++i) {
    ring.emplace_back(Vec3f(0, 0, i * (depth / ring_num)));
  }
}


void BgRing::update() {
  for (auto &pos : ring) {
    pos.z -= speed;
    if (pos.z <= 0.0f) {
      pos.z += depth;
    }
  }
}

void BgRing::draw() {
  for (auto &pos : ring) {
    if (pos.z < 20) {
        ly::drawStrokedCircle(pos.xy() / pos.z + getWindowCenter(),
                              radius / pos.z,
                              40, Color::white());
    }
  }
}