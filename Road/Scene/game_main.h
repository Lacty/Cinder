
#pragma once
#include "scene.h"
#include "../Object/star.h"
#include "../Object/ring.h"
#include <vector>


class GameMain : public Scene {
private:
  Star star;
  Ring ring;

public:
  GameMain(SceneMgr*);

  void update();
  void draw();
};