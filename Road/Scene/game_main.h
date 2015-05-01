
#pragma once
#include "scene.h"


class GameMain : public Scene {
private:

public:
  GameMain(SceneMgr*);

  void update();
  void draw();
};