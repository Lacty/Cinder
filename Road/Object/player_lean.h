
#pragma once
#include "Iobject.h"


class PlayerLean : public IObject {
private:
  const float angle_speed = 0.1f;
  float lean_angle;

  void leanLeft();
  void leanRight();
  void leanBound();

public:
  PlayerLean(Player*);

  void update();

  float getLeanAngle() const;
};