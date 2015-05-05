
#pragma once
#include "Iobject.h"


class PlayerLean : public IObject {
private:
  struct AngleStatus {
    const float center    =  0.0f;
    const float left_max  = -2.0f;
    const float right_max =  2.0f;
    const float speed     =  0.1f; 
  } angle_status;
  float lean_angle;

  void leanLeft();
  void leanRight();
  void leanCenter();
  void leanBound();

public:
  PlayerLean(Player*);

  void update();

  float getLeanAngle() const;
};