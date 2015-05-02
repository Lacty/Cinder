
#pragma once
#include "../MyLib/common.h"
#include <vector>


class Star {
private:
  std::vector<Vec3f> star;
  float radius;
  float depth;
  float speed;
  Vec2f move;

public:
  Star(const int&   star_num,
       const float& radius,
       const float& depth,
       const float& speed);

  void update(const Vec2f& move);
  void update();
  void draw();
};