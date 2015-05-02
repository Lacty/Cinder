
#include "ring.h"
#include "../MyLib/graph.h"


Ring::Ring(const int& ring_num,
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


void Ring::update() {
  for (auto &pos : ring) {
    pos.z -= speed;
    if (pos.z <= 0.0f) {
      pos.z += depth;
    }
  }
}

void Ring::draw() {
  for (auto &pos : ring) {
    if (pos.z < 20) {
      ly::drawStrokedCircle(Vec2f(pos.x / pos.z + (int(WindowSize::Width) / 2),
                                  pos.y / pos.z + (int(WindowSize::Height) / 2)),
                            radius / pos.z,
                            100, Color::white());
    }
  }
}