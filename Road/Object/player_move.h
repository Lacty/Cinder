
#pragma once
#include "Iobject.h"
#include "../MyLib/common.h"


enum class LeanStatus {
  Center,
  Left,
  Right
};

class PlayerMove : public IObject {
private:
  struct Edge {
    const float left  = -200.0f;
    const float right =  200.0f;
  } edge;
  const float Speed = 4.0f;
  Vec3f pos;
  LeanStatus lean_status;

  void moveLeft();
  void moveRight();
  void moveBound();

public:
  PlayerMove(Object*);

  void  update();
  Vec3f getPos();
};