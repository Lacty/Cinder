
#pragma once
#include "Iobject.h"


class PlayerMove : public IObject {
private:

public:
  PlayerMove(Object*);

  void update();
  void draw();
};