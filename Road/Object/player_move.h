
#pragma once
#include "Iobject.h"
#include "../MyLib/common.h"


enum class LeanStatus {
  Left,
  Right
};

class PlayerMove : public IObject {
private:
  Vec3f pos;
  LeanStatus lean_status;

  void moveLeft();
  void moveRight();

public:
  PlayerMove(Object*);

  void  update();
  Vec3f getPos();
};