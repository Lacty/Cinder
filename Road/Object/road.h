
#pragma once
#include "../Mylib/common.h"
#include <vector>


class Road {
private:
  struct Line {
    Vec3f begin;
    Vec3f end;
  };
  std::vector<Line> lines;
  std::vector<Line> rane;

  enum RoadNum { Road_Max = 20 };
  float depth[Road_Max];
  float speed;

public:
  Road();

  void update();
  void draw();
};