
#pragma once
#include "../MyLib/common.h"
#include <vector>


class BoostRing {
private:
  enum Rane {
    Center,
    Left,
    Right
  };

  struct Ring {
    Rane  rane;
    Vec3f pos;
  };
  std::vector<Ring> m_ring;

  float distance;
  float radius;
  float speed;
  int   segment_num;

public:
  BoostRing();

  void update();
  void draw();
};