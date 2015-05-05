
#pragma once
#include "Iobject.h"
#include "../MyLib/common.h"


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
  void moveCenter();
  void moveBound();

public:
  PlayerMove(Player*);

  void  update();

  Vec3f      getPos()  const;
  LeanStatus getLean() const;
};