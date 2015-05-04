
#pragma once
#include "../Mylib/common.h"
#include <vector>


class BgRing {
private:
  std::vector<Vec3f> ring;
  float radius;
  float depth;
  float speed;
  float offset;
  Vec2f move;


public:
  BgRing(const int&   ring_num,
         const float& radius,
         const float& depth,
         const float& speed);

  void update();
  void draw();
};