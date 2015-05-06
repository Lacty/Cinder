
#pragma once
#include "../MyLib/common.h"
#include "Iobject.h"


class PlayerModel : public IObject {
private:
  struct Line {
    Vec3f begin;
    Vec3f end;
  };
  std::vector<Line> lines;
  float angle;

public:
  PlayerModel(Player*);

  void update();
  void draw();
};