
#include "star.h"
#include "../MyLib/graph.h"
#include "cinder/Rand.h"


Star::Star(const int&   star_num,
           const float& radius,
           const float& depth,
           const float& speed) :
move(Vec2f::zero()),
radius(radius),
depth(depth),
speed(speed)
{
  for (int i = 0; i < star_num; ++i) {
    star.emplace_back(Vec3f(randFloat(-int(WindowSize::Width), int(WindowSize::Width)),
                            randFloat(int(WindowSize::Height), -int(WindowSize::Height)),
                            randFloat(1.0f, this->depth)));
  }
}


void Star::update(const Vec2f& move) {
  this->move = move;
  for (auto &it : star) {
    it.z -= speed;
    if (it.z <= 0.0f) {
      it.z += depth;
    }
  }
}

void Star::update() {
  for (auto &it : star) {
    it.z -= speed;
    if (it.z <= 0.0f) {
      it.z += depth;
    }
  }
}

void Star::draw() {
  for (auto &pos : star) {
    ly::drawCircle(Vec2f(pos.x / pos.z + (int(WindowSize::Width) / 2) + move.x,
                         pos.y / pos.z + (int(WindowSize::Height) / 2) + move.y),
                         radius / pos.z, 0, Color::white());
  }
}